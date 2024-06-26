#!/usr/bin/python3

# This script can be used for building the project and other project related tasks.

import os
import sys

build_cmd = "colcon build --symlink-install"
bulid_status=0
os.system("/opt/ros/jazzy/setup.sh")

MAIN_OPS = {"build": "builds the packages for you",
            "install": "install the prerequisite drivers",
            "clean": "Clean the install build and log folder"}
BUILD_OPS = {"all":"builds all the packages",
             "package": "builds selected packages",
             "pc": "only build observer/viz packages"}

def print_oops(ops):
    for key, value in ops.items():
        print(key + " : " + value)


def build(sub_cmd, packages):
    if (sub_cmd == list(BUILD_OPS.keys())[0]):
        bulid_status = os.system(build_cmd)

    elif (sub_cmd == list(BUILD_OPS.keys())[1]):
        bulid_status = os.system(build_cmd + " --packages-up-to" + packages)
        #TODO: Add pc and nandhi case.
    else:
        print("Invalid command\noptions are:")
        print_oops(BUILD_OPS)


def install_driver():
    os.system("mkdir -p build/yd_lidar_driver && \
        cd build/yd_lidar_driver && cmake ../../drivers/YDLidar-SDK && \
            make && sudo make install")


def run_option():
    if len(sys.argv) == 1:
        print("options are:")
        print_oops(MAIN_OPS)
        exit()

    cmd = sys.argv[1]
    if cmd == list(MAIN_OPS.keys())[0]:
        param = ""
        sub_cmd = sys.argv[2]
        for i in range(3, len(sys.argv)):
            param = param + " " + sys.argv[i] + " "
        build(sub_cmd, param)
    elif cmd == list(MAIN_OPS.keys())[1]:
        install_driver()
    elif cmd == list(MAIN_OPS.keys())[2]:
        bulid_status = os.system("rm -rf build install log")
        print("Deleted the build artifacts")
    else:
        print("Invalid command\noptions are:")
        print_oops(MAIN_OPS)


def main():
    print("Ambhaaa!")

    run_option()
    print("The build return vaule " + str(bulid_status))
    exit(bulid_status)


if __name__ == "__main__":
    main()
