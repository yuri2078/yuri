# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "record_writer",
    srcs = ["record_writer.cc"],
    deps = [
        "//cyber/demo_protobuf/test_01:student_cc",
        "//cyber"
    ],
)

cc_binary(
    name = "record_reader",
    srcs = ["record_reader.cc"],
    deps = [
        "//cyber"
    ],
)