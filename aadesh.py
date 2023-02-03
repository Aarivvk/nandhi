#!/usr/bin/python3

# This script can be used for building the project and other project related tasks.

import os
import sys

build_cmd = "colcon build --packages-skip vehicle_state_estimator --symlink-install"

os.system("/opt/ros/rolling/setup.zsh")


def build(sub_cmd, packages):
    if(sub_cmd == "all"):
        res = os.system(build_cmd)

    elif(sub_cmd == "package"):
        res = os.system(build_cmd + " --packages-up-to" + packages)
    else:
        print("Invalid command\noptions are: \nall \npackage")


def install_driver():
    os.system("mkdir -p build/yd_lidar_driver && \
        cd build/yd_lidar_driver && cmake ../../drivers/YDLidar-SDK && \
            make && sudo make install")


def run_option():
    if len(sys.argv) == 1:
        print("options are: \nbuild \ninstall")
        exit()

    cmd = sys.argv[1]
    if cmd == "build":
        param = ""
        sub_cmd = sys.argv[2]
        for i in range(3, len(sys.argv)):
            param = param + " " + sys.argv[i] + " "
        build(sub_cmd, param)
    elif cmd == "install":
        install_driver()
    else:
        print("Invalid command\noptions are: \nbuild \ninstall")

def main():
    print("Ambhaaa!")

    run_option()


if __name__ == "__main__":
    main()
