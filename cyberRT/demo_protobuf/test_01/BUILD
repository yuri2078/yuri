package(default_visibility = ["//visibility:public"]) #使这个包的文件共享

#把proto文档生成为lib文件
proto_library(
    name = "student_proto",
    srcs = ["student.proto"],
)

#把已经有了的proto 文档编译成cc文档
cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"],
)


cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":student_cc"],
)