import pygame
import numpy as np
import cv2
from geometry_msgs.msg import Twist  # Assuming this message type is already available
import threading
import os
from ament_index_python.packages import get_package_share_directory

class PygameOpenCVCarControl:
    def __init__(self, width=600, height=500):
        """
        Initializes the Pygame window, OpenCV image handling, and car control system.
        
        Args:
            width (int): Width of the window.
            height (int): Height of the window.
        """
        # Initialize Pygame
        pygame.init()

        # Window settings
        self.WIDTH, self.HEIGHT = width, height
        self.screen = pygame.display.set_mode((self.WIDTH, self.HEIGHT))
        pygame.display.set_caption("Pygame + OpenCV Car Control")

        # Control properties
        self.steering_angle = 0  # Steering wheel angle (-1 to 1)
        self.speed = 0  # Vehicle speed (-1 to 1)

        # Vehicle command
        self.vehicle_command = Twist()

        # Font for display
        self.font = pygame.font.Font(None, 36)

        # Flag to control the running state
        self.running = True
        self.current_frame = None

        # Start the interface thread
        self.interface_thread = threading.Thread(target=self.__run, daemon=True)
        self.interface_thread.start()

    def update(self, cv2_image):
        """
        Update the system with new data.

        Args:
            cv2_image (numpy.ndarray): OpenCV image to display.
            twist_msg (geometry_msgs/Twist, optional): Twist message with linear and angular commands.
            
        Returns:
            geometry_msgs/Twist: The updated Twist message.
        """

        # Now display the image and controls
        self.display(cv2_image)

        return self.vehicle_command

    def display(self, cv2_image):
        """
        Display the image and the current control state on the screen.
        
        Args:
            cv2_image (numpy.ndarray): Image to display.
        """
        # Resize the frame to fit the window
        frame_resized = cv2.resize(cv2_image, (self.WIDTH, self.HEIGHT - 100))

        # Convert OpenCV image to Pygame format
        frame_surface = self.convert_cv2_to_pygame(frame_resized)

        # Draw OpenCV image
        self.screen.blit(frame_surface, (0, 0))

        # Clear the text area before new values are drawn
        pygame.draw.rect(self.screen, (0, 0, 0), (0, self.HEIGHT - 100, self.WIDTH, 100))

        # Display text on the screen at the bottom
        # The text is positioned at the bottom of the screen for better readability and to avoid overlapping with the displayed image.
        self.screen.blit(self.font.render(f"Steering: {self.steering_angle:.2f}", True, (255, 255, 255)), (70, self.HEIGHT - 70))
        self.screen.blit(self.font.render(f"Speed: {self.speed:.2f}", True, (255, 255, 255)), (370, self.HEIGHT - 70))

        pygame.display.flip()

    def convert_cv2_to_pygame(self, cv2_img):
        """Convert OpenCV image to Pygame format."""
        cv2_img = cv2.cvtColor(cv2_img, cv2.COLOR_BGR2RGB)  # Convert BGR to RGB
        cv2_img = np.rot90(cv2_img)  # Rotate for Pygame
        return pygame.surfarray.make_surface(cv2_img)

    def handle_control(self, steering_delta, speed_delta):
        """
        Handle manual control updates for steering and speed.
        
        Args:
            steering_delta (float): Change in steering angle (-1 to 1).
            speed_delta (float): Change in speed (-1 to 1).
        """
        # Update steering angle and speed with limits
        self.steering_angle = np.clip(self.steering_angle + steering_delta, -1, 1)
        self.speed = np.clip(self.speed + speed_delta, -1, 1)

        # Update vehicle command
        self.vehicle_command.angular.z = self.steering_angle
        self.vehicle_command.linear.x = self.speed

    def stop(self):
        """Stop the interface and close the Pygame window."""
        self.running = False

    def __run(self):
        """Main loop to display OpenCV images and handle control."""
        while self.running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_LEFT:
                        self.handle_control(-0.1, 0)
                    elif event.key == pygame.K_RIGHT:
                        self.handle_control(0.1, 0)
                    elif event.key == pygame.K_UP:
                        self.handle_control(0, 0.1)
                    elif event.key == pygame.K_DOWN:
                        self.handle_control(0, -0.1)
                    elif event.key == pygame.K_SPACE:
                        self.vehicle_command = Twist()  # Reset vehicle command
                        self.steering_angle = 0
                        self.speed = 0

            pygame.time.delay(100)  # Slow down the loop for real-time control

        print("Exiting Pygame thread...")

    def __del__(self):
        """Stop the interface and close the Pygame window."""
        self.running = False
        self.interface_thread.join()
        pygame.quit()
