from setuptools import find_packages, setup

package_name = 'rl'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='vk',
    maintainer_email='8676836+Aarivvk@users.noreply.github.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'nandhi_control_center = rl.nandhi_control_center:PygameOpenCVCarControl',
            'ros_client = rl.ros_sim_client:RosSimClient',
            'rl_agent = rl.rl_agent:main'
        ],
    },
)
