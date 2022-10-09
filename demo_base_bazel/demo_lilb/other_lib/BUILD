# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "hello",
    srcs = ["hello.cc"],
    deps = ["//lib_hello:get_name_lib"], #添加lib_hello文件夹下面build文件夹中的get_name_lib 文件
)