<template>
  <el-card class="login-card">
    <el-form :model="form" ref="loginForm" :rules="rules" label-width="80px" class="login-form">
      <el-form-item label="用户名" prop="username">
        <el-input v-model="form.username" placeholder="请输入用户名"></el-input>
      </el-form-item>
      <el-form-item label="密码" prop="password">
        <el-input v-model="form.password" placeholder="请输入密码" show-password></el-input>
      </el-form-item>
      <el-form-item>
        <el-button type="primary" @click="login">登录</el-button>
        <el-button type="primary" @click="cpp">测试</el-button>
      </el-form-item>
    </el-form>
  </el-card>
  
  <el-card id="cpp">
    {{ val }}
  </el-card>
</template>

<script lang="ts">
import { defineComponent, ref } from 'vue';
import { ElForm, ElFormItem, ElInput, ElButton, ElCard } from 'element-plus';
import axios from 'axios'
import { ElNotification } from 'element-plus'

export default defineComponent({
  components: {
    ElForm,
    ElFormItem,
    ElInput,
    ElButton,
    ElCard,
  },
  setup() {
    const form = ref({
      username: '',
      password: '',
    });

    const val = ref()

    const rules = {
      username: [
        { required: true, message: '请输入用户名', trigger: 'blur' },
      ],
      password: [
        { required: true, message: '请输入密码', trigger: 'blur' },
      ],
    };

    const cpp = async () => {
      try {
        let get = await axios.post("http://localhost:2078");
        val.value = get.data;
      } catch (error: any) {
        ElNotification.error(error)
      }
    }

    const login = () => {
      // 登录逻辑
    };
    
    return {
      form,
      rules,
      login,
      cpp,
      val
    };
  },
});
</script>

<style scoped>
.login-card {
  width: 400px;
  margin: 0 auto;
  margin-top: 200px;
  padding: 20px;
}
.login-form {
  margin-top: 20px;
}

#cpp {
  margin-top: 30px;
  margin: 30px 23%;
  width: 50%;
  text-align: center;
}
</style>

