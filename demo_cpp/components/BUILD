
load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
proto_library(
    name = "Student_proto",
    srcs = ["Student.proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_proto_library(
    name = "Student_proto_cc",
    deps = [":Student_proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "my_components_lib",
    srcs = ["my_components.cc"],
    hdrs = ["my_components.h"],
    deps = [
        "//cyber",
        "//cyber/component",
        "//cyber/demo_cpp/components:Student_proto_cc"
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "my_components.so",
    linkshared = True, 
    linkstatic = False,
    deps = [":my_components_lib"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "talker",
    srcs = ["talker.cc"],
    deps = [
        "//cyber",
        ":Student_proto_cc"
    ],
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

    runtime_dest = "cyber/demo_cpp/components",
    targets = [
        ":talker",
        ":my_components.so",
    ],
)