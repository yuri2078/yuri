# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
package(default_visibility = ["//visibility:public"])
cc_binary(
    name = "talker", #项目名字
    srcs = ["talker.cc"], #项目文件
    deps = [
        "//cyber",
        "//cyber/demo_protobuf/test_01:student_cc"
    ], #固定写法
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "listener",
    srcs = ["listener.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_protobuf/test_01:student_cc"
    ], #固定写法
    
)