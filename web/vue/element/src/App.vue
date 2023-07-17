<template>
  
  <div id="system" v-if="ready == true">
    <div id="left">
      <h1>花生</h1>
      <button id="search">搜索</button>
      <hr style="margin: 12px" />
      <h2>内容</h2>
      <div
        v-for="(iteam, index) in lists"
        :key="iteam.icon"
        @click="callBack(index)"
        class="iteams"
        :class="{ 'iteams-active': selectedIndex === index }"
        :style="iteam.icon"
      >
        {{ iteam.name }}
      </div>

      <div id="outlogin" @click="outLogin">退出登陆</div>
    </div>

    <el-container id="right">
      <el-header id="header-container">
        <span>当前用户 : {{ this.user.username }} </span>
        <el-avatar icon=UserFilled />
      </el-header>
      

      <el-main id="main-container">
		<router-view :message="user" :carCompare="comCars" @addComCar="addComCar"></router-view>
	</el-main>
    </el-container>
  </div>


  <login v-else @is-login="readyToLogin"/>
</template>


<script>
import { ElMessage } from 'element-plus';
import login from './components/login.vue';
import page5 from './components/page5.vue'

export default {
  components: { login, page5 },
	props: ['message', 'carCompare'],
  data() {
    return {
      msg: "this is student page!",
      ready: false,
      selectedIndex: 0,
      user: {},
      comCars: [],
      test:[],
      lists: [
        {
          icon: "background-image: url('src/assets/icons/标签.svg')",
          name: "最新信息",
        },
        {
          icon: "background-image: url('src/assets/icons/表情.svg')",
          name: "我的收藏",
        },
        {
          icon: "background-image: url('src/assets/icons/积分.svg')",
          name: "进入对比",
        },
        {
          icon: "background-image: url('src/assets/icons/解锁.svg')",
          name: "品牌管理",
        },
        {
          icon: "background-image: url('src/assets/icons/图片.svg')",
          name: "登记车辆",
        },
        {
          icon: "background-image: url('src/assets/icons/云端.svg')",
          name: "主题",
        },
        {
          icon: "background-image: url('src/assets/icons/咨询.svg')",
          name: "菜单",
        },
        {
          icon: "background-image: url('src/assets/icons/定位.svg')",
          name: "插件",
        },
      ],
    };
  },
  methods: {
    callBack(index) {
      this.selectedIndex = index;
      console.log("index -> " + index);
      this.$router.push("/student/" + index);
    },
    readyToLogin(userInfo) {
      this.user = userInfo;
      this.ready = true;
    },
    outLogin() {
      this.ready = false;
      this.carCompare = [];
    },

    addComCar(row) {
      let flag = false;
      this.comCars.forEach(element => {
        if (element.id == row.id) {
          ElMessage.error("已经添加过了捏!");
          flag = true;
          return;
        }
      });
      if (flag == false) {
        ElMessage.success("加入 " + row.id + " 成功!");
        this.comCars.push(row);
      }
    }
  },
};
</script>



<style scoped>
* {
  margin: 0;
  padding: 0 !important;
  box-sizing: border-box;
}
#system {
  width: 100vw;
  height: 100vh;
  background-color: aliceblue;
  display: flex;
}

#left {
  width: 350px;
  height: 100%;
  background-color: white;
  display: flex;
  flex-direction: column;
}

#right {
  flex-grow: 1;
  height: 100%;
}

#left > h1 {
  width: 100%;
  height: 80px;
  text-align: center;
  margin: 12px;
  font-size: 60px;
  color: #097bed;
}

#search {
  width: 100% - 40px;
  height: 70px;
  background-image: url("./assets/icons/搜索.svg");
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
  color: #a09c9c;
  margin: 12px 22px;
}

.iteams {
  transition-duration: 0.4s;
  width: 100% - 40px;
  height: 70px;
  background-repeat: no-repeat;
  background-position: 0px center;
  background-size: 35px;
  cursor: pointer;
  border: none;
  border-radius: 12px;
  margin: 0 30px 15px 30px;
  font-size: 28px;
  text-align: center;
  line-height: 70px;
}

.iteams:hover {
  background-color: #f3f4f6;
  transition-duration: 0.4s;
  background-position: 30px center;
}

.iteams-active {
  background-color: #f3f4f6;
  transition-duration: 0.4s;
  background-position: 40px center;
}

#outlogin {
  transition-duration: 0.4s;
  width: 100% - 24px;
  height: 80px;
  margin: 200px 12px 0px 12px;
  background-color: #c70922;
  border-radius: 30px;
  color: white;
  font-size: 50px;
  text-align: center;
  line-height: 80px;
  cursor: pointer;
}

#outlogin:hover {
  font-size: 60px;
  transition-duration: 0.4s;
}

#header-container {
  height: 80px;
  background-color: beige;
  display: flex;
  background-color: #dcdfe4;
  color: #333;
  font-size: 32px;
  justify-content: center;
  align-items: center;
  /* margin-top: 10px; */
}

#header-container > .el-avatar{
  width: 48px;
  height: 48px;
  margin: 12px;
}

#main-container {
  background-color: aliceblue;
}
.el-main, .el-heder {
  padding: 0 !important;
}


</style>