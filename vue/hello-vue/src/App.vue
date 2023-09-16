<template>
	<div id="system" v-if="ready == true">
		<div id="left">
			<h1>Halo</h1>
			<button id="search">搜索</button>
			<hr style="margin: 12px" />
			<h2>内容</h2>
			<div
				v-for="(iteam, index) in lists"
				:key="iteam.icon"
				@click="callBack(index)"
				class="iteams"
                :class="{'iteams-active': selectedIndex === index}"
				:style="iteam.icon"
			>
				{{ iteam.name }}
			</div>

			<div id="outlogin" @click="outLogin">
				退出登陆
			</div>
            
		</div>

		<div id="right">
            <router-view></router-view>
		</div>
	</div>
	<login v-else @is-login="readyToLogin" />
</template>


<script>
import login from './components/login.vue';

export default {
	components: { login },
	emits: ['isClick'],
	data() {
		return {
			msg: 'this is student page!',
            ready: false,
            selectedIndex:0,
			lists: [
				{
					icon: "background-image: url('src/assets/icons/标签.svg')",
					name: '学生信息'
				},
				{
					icon: "background-image: url('src/assets/icons/表情.svg')",
					name: '学生成绩'
				},
				{
					icon: "background-image: url('src/assets/icons/积分.svg')",
					name: '课程信息'
				},
				{
					icon: "background-image: url('src/assets/icons/解锁.svg')",
					name: '附件'
				},
				{
					icon: "background-image: url('src/assets/icons/图片.svg')",
					name: '连接'
				},
				{
					icon: "background-image: url('src/assets/icons/云端.svg')",
					name: '主题'
				},
				{
					icon: "background-image: url('src/assets/icons/咨询.svg')",
					name: '菜单'
				},
				{
					icon: "background-image: url('src/assets/icons/定位.svg')",
					name: '插件'
				}
			]
		};
	},
	methods: {
        callBack(index) {
            this.selectedIndex = index;
			console.log('index -> ' + index);
			this.$router.push('/student/' + index);
        },
        readyToLogin() {
            console.log("登陆成功!");
            this.ready = true;
		},
		outLogin() {
			this.ready = false;
		}
	}
};
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
	background-image: url('./assets/icons/搜索.svg');
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
	margin: 12px;
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
	margin: 0 20px 20px 20px;
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
</style>