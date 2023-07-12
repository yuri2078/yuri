<template>
  <div id="system" v-if="ready == false">
      <div id = "left">
          <h1>Halo</h1>
          <button id="search">搜索</button>
          <hr style="margin: 12px;">
          <h2>内容</h2>
          <div v-for="iteam in lists" :key='iteam.icon' class="iteams" :style= "iteam.icon">{{ iteam.name }}</div>
      </div>

      <div id = right>
          <button @click="callBack">点我</button>
          <router-view></router-view>
      </div>
  </div>
  <login v-else />
</template>


<script>
import login from './components/login.vue'

export default {
  components: { login },
  emits: ['isClick'],
  data() {
      return {
        msg: "this is student page!",
        ready: false,
        lists: [
            { icon: "background-image: url('src/assets/icons/标签.svg')", name: "学生信息" },
            { icon: "background-image: url('src/assets/icons/表情.svg')", name: "学生成绩" },
            { icon: "background-image: url('src/assets/icons/积分.svg')", name: "课程信息" },
            { icon: "background-image: url('src/assets/icons/解锁.svg')", name: "附件" },
            { icon: "background-image: url('src/assets/icons/图片.svg')", name: "连接" },
            { icon: "background-image: url('src/assets/icons/云端.svg')", name: "主题" },
            { icon: "background-image: url('src/assets/icons/咨询.svg')", name: "菜单" },
            { icon: "background-image: url('src/assets/icons/定位.svg')", name: "插件" },
        ]
          
      }
  },
  methods: {
      callBack() {
          this.$router.push('/hello')
      }
  }
}

</script>

<style scoped>

  * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
  }
  #system {
      width: 100vw;
      height: 100vh;
      background-color: aliceblue;
  }

  #left {
      width: 30%;
      height: 100%;
      max-width: 400px;
      min-width: 300px;
      background-color: white;
      float: left;
      display: flex;
      flex-direction: column;
  }

  #right {
      width: auto;
      height: 100%;
      float: left;
  }

  #left > h1 {
      width: 100%;
      height: 80px;
      text-align: center;
      margin: 12px;
      font-size: 60px;
      color: #097BED;
  }

  #search {
      width: 100% - 40px;
      height: 70px;
      background-image: url("../assets/icons/搜索.svg");
      background-repeat: no-repeat;
      background-position: 12px center;
      background-size: 35px;
      cursor: pointer;
      border: none;
      border-radius: 12px;
      margin: 0 20px 0 20px;
      font-size: 28px;
  }

  #left > h2 {
      color: #A09C9C;
      margin: 12px;
  }

  .iteams {
      width: 100% - 40px;
      height: 70px;
      background-repeat: no-repeat;
      background-position: 0px center;
      background-size: 35px;
      cursor: pointer;
      border: none;
      border-radius: 12px;
      margin: 0 20px 20px 20px;
      font-size: 28px;
      text-align: center;
      line-height: 70px;
  }

  .iteams:hover{
      background-color: #F3F4F6;
  }


</style>