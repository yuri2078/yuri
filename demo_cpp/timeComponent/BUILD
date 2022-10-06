load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "timeComponent_lib",
    srcs = ["timeComponent.cc"],
    hdrs = ["timeComponent.h"],
    deps = ["//cyber"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "timeComponent.so",
    linkshared = True,
    linkstatic = False,
    deps = [":timeComponent_lib"],
)

filegroup(
    name = "conf",
    srcs = [
        ":cpt.dag",
        ":cpt.launch",
    ],
)

install (
    name = "install",
    data = [
        ":conf",
    ],

    runtime_dest = "cyber/demo_cpp/timeComponent",
    targets = [
        ":timeComponent.so",
    ],
)