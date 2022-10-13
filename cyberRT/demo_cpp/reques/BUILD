package(default_visibility = ["//visibility:public"])

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
proto_library(
    name = "request_proto",
    srcs = ["request.proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_proto_library(
    name = "request_cc",
    deps = [":request_proto"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_cpp/reques:request_cc"
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_cpp/reques:request_cc"
    ],
)