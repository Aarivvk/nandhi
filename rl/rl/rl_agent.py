from rl.ros_sim_client import RosSimClient


def main():
    client = RosSimClient()
    client.request(reset=True)

    while client.is_ros_okay():
        crash, t_distance = client.request(step=True)
        client.display()
        if crash is None or t_distance is None:
            print("Invalid observations...")

        if crash:
            print("Crashed!")
            print("Resetting...")
            client.request(reset=True)
            print("resetting done")
        
        if t_distance < 0.5:
            print("Goal reached!")
            print("Resetting...")
            client.request(reset=True)
            print("resetting done")

    client.request(reset=True)

if __name__ == "__main__":
    main()