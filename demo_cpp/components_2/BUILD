load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
proto_library(
    name = "radar_proto",
    srcs = ["radar.proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_proto_library(
    name = "radar_proto_cc",
    deps = [":radar_proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "talker_front",
    srcs = ["talker_front.cc"],
    deps = [
        "//cyber",
        ":radar_proto_cc"
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "talker_back",
    srcs = ["talker_back.cc"],
    deps = [
        "//cyber",
        ":radar_proto_cc"
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "my_components_2_lib",
    srcs = ["my_components_2.cc"],
    hdrs = ["my_components_2.h"],
    deps = [
        "//cyber",
        ":radar_proto_cc"
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "my_components_2.so",
    linkshared = True, 
    linkstatic = False,
    deps = [":my_components_2_lib"],
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

    runtime_dest = "cyber/demo_cpp/components_2",
    targets = [
        ":talker_front",
        ":talker_back",
        ":my_components_2.so",
    ],
)