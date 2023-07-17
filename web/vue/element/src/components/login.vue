<template>
  <div id="login-back">
    <div id="login">
      <div id="login-top">
        <p>欢迎光临</p>
      </div>
      <div id="login-center">
        <input
          id="username"
          placeholder="账号"
          type="text"
          v-model="username"
        />
        <input
          id="password"
          placeholder="密码"
          type="password"
          v-model="password"
        />
      </div>

      <div id="verify">
        <p>验证码 : {{ verify }}</p>
        <input v-model="user_verify" />
      </div>

      <div id="login-buttom">
        <button @click="register">注册</button>
        <button @click="anonymous">游客登陆</button>
        <button @click="login($event)">登陆</button>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";
import { ElMessage } from "element-plus";
export default {
  emits: ["isLogin"],
  data() {
    return {
      username: "",
      password: "",
      verify: "",
      user_verify: "",
      login_readey: false,
      userInfo: {},
    };
  },
  created() {
    this.verify = Math.floor(1000 + Math.random() * 9000).toString();
  },
  methods: {
    login(e) {
      let passwd = false;
      if (this.username === "" || this.password === "") {
        this.$message({
          type: "warning",
          message: "账号或者密码为空!",
        });
        return;
      } else if (this.verify !== this.user_verify) {
        ElMessage.error("验证码错误!");
        return;
      } else {
        passwd = true;
      }

      axios.post("http://localhost:8080/login", {
          username: this.username,
          password: this.password,
        })
        .then((response) => {
          if (response.data.id === undefined) {
            this.$message({
              type: "warning",
              message: "没有该用户请先注册！",
            });
          } else if (this.password !== response.data.password) {
            ElMessage.error("密码错误!");
          } else {
            this.$message({
              type: "success",
              message: "登陆成功！欢迎 " + this.username,
            });

            this.$emit("isLogin", response.data);
          }
        })
        .catch((e) => {
          ElMessage.error(e);
        });
    },
    register() {
      this.$prompt("密码密码长度为6-10位", "请再输入一遍", {
        confirmButtonText: "确定",
        cancelButtonText: "取消",
        inputPattern: /^.{6,10}$/,
        inputErrorMessage: "密码格式不正确",
      })
        .then(({ value }) => {
          if (value === this.password) {
            this.$message({
              type: "success",
              message: "注册成功!",
            });
          } else {
            this.$message({
              type: "error",
              message: "两次密码不相同!!!",
            });
          }
        })
        .catch(() => {
          this.$message({
            type: "info",
            message: "取消输入",
          });
        });
    },
    anonymous() {
      this.$message({
        type: "success",
        message: "游客登陆成功!",
      });
      this.$emit("isLogin", {
        id:-1,
        username: 'anonymous',
        manager:false
      });
    },
  },
};
</script>

<style scoped>
#login-back {
  width: 100vw;
  height: 100vh;
  background-color: rgb(95, 158, 158);
  display: flex;
  justify-content: center;
  align-items: center;
}

#login {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  border: 2px solid white;
  border-radius: 22px;
  width: 600px;
  height: 600px;
  position: relative;
  z-index: 100;
  text-align: center;
  background-color: rgba(18, 178, 184, 0.5);
  filter: blur(10);
}

#login-top > p {
  font-family: "Fira Code Medium";
  font-weight: 700;
  width: 100%;
  height: 80px;
  font-size: 70px;
  text-align: center;
  color: white;
  margin-top: 50px;
  margin-bottom: 80px;
}

#login-center {
  width: 100%;
  height: 180px;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-items: center;
}

#username,
#password {
  width: 400px;
  height: 60px;
  margin: 10px 100px 10px 100px;
  font-size: 26px;
}

#login::before {
  content: "";
  width: calc(100% + 70px);
  height: calc(100% + 70px);
  box-shadow: inset 0 0 0 10px rgba(255, 255, 255, 0.25);
  position: absolute;
  top: -30px;
  left: -35px;
  z-index: -1;
  border-radius: 18px;
  filter: blur(2px);
  overflow: hidden;
}

#login input::placeholder {
  color: #3d5245;
}

#login input,
#login button {
  padding: 10px;
  margin-bottom: 10px;
  border-radius: 7px;
  background-color: rgb(255, 255, 255, 0.3);
  color: #3d5245;
  border: none;
  -webkit-appearance: none; /*去除阴影边框*/
  appearance: none;
  outline: none;
}

/* 补充，取消选中高亮蓝框 */
#login button:focus,
#login input:focus {
  outline: 0;
}

#login button:hover {
  background-color: #3d5245;
  color: white;
  cursor: pointer;
  position: relative;
  transition-duration: 0.4s;
}

#login button:hover::after {
  content: "";
  width: 150px;
  height: 67px;
  background-color: #3d5245;
  filter: blur(30px);
  position: absolute;
  z-index: -1;
  top: 0px;
  left: 0px;
}

#login-buttom button {
  width: 130px;
  height: 60px;
  margin: 0 30px 30px 30px;
  font-size: 25px;
}

#verify {
  width: 400px;
  height: 60px;
  margin-bottom: 20px;
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: center;
  /* background-color: #3d5245; */
}

#verify > p {
  font-size: 32px;
  line-height: 60px;
  margin: 0 10px 10px 0;
}

#verify input {
  width: 140px;
  font-size: 26px;
}
.el-main {
  padding: 0 !important;
}
</style>