package(default_visibility = ["//visibility:public"]) #使这个包的文件共享

#把proto文档生成为lib文件
proto_library(
    name = "person_proto",
    srcs = ["person.proto"],
)

#把已经有了的proto 文档编译成cc文档
cc_proto_library(
    name = "person_cc",
    deps = [":person_proto"],
)
