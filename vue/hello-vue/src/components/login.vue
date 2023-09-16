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
                <p>验证码 : {{ verify }} </p>
                <input v-model="user_verify">
            </div>

			<div id="login-buttom">
				<button @click="register">注册</button>
				<button @click="login($event)">登陆</button>
			</div>
		</div>
	</div>
</template>

<script>
import axios from 'axios';
export default {
	emits: ['isLogin'],
	data() {
		return {
			username: '',
			password: '',
            verify: '',
            user_verify:'',
			login_readey: false,
		};
	},
    created() {
        this.verify = Math.floor(1000 + Math.random() * 9000).toString();
    },
	methods: {
		login(e) {
			// axios.post("http://localhost:8080/login", null, {
			//     params: {
			//         sno : 207817
			//     }
			// }).then((response) => {
			//     this.student = response.data;
			//     if (response.data.sname != null) {
			//         console.log(response.data);
			//     } else {
			//         console.log("登陆失败!");
			//     }
			// });

			if (this.username === '' || this.password === '') {
				alert('账号或者密码为空!');
			} else if(this.verify === this.user_verify) {
				alert('登陆成功!');
				this.$emit('isLogin');
				console.log('name -> ' + this.username + ' passwd -> ' + this.password);
            } else {
                alert("验证码错误!!");
            }
		},
		register() {
			
		}
	}
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
	font-family: 'Fira Code Medium';
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
	content: '';
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
	content: '';
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
    margin:0 10px 10px 0;
}

#verify input {
    width: 140px;
    font-size: 26px;
}

</style>