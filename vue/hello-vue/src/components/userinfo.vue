<template>
    <div>
        <h1>学生信息管理</h1>
        <button @click="getData"></button>
        <table>
            <tr>
                <th v-for="(value,key,index) in students[0]" :key="index">{{ key }}</th>
            </tr>

            <tr v-for="student in students" :key="student.sno">
                <td v-for="(value, key, index) in student" :key="index">{{ value }}</td>
            </tr>


        </table>
        
    </div>
	
</template>

<script>
export default {
	data() {
        return {
            students:'',
            message:''
		};
    },

    created() {
        this.getData();
    },
    methods: {
        async getData() {
            try {
                let get = await axios.get("http://localhost:8080/findStudent", null);
                console.log(get.data);
                this.students = get.data
            } catch (error) {
                this.students = null;
                console.log(error);
                alert("获取数据出错!");
            }
        }
    }
};
import axios from 'axios';
</script>

<style scoped>

* {
    padding: 0px;
    margin: 0px;
    box-sizing: border-box;
}

div {
    width:100%;
    height: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
}

h1 {
	text-align: center;
	font-size: 80px;
	color: grey;
}

table {
    /* border: 2px solid black; */
    width: 800px;
    height: 800px;
}

tr, td, th {
    border: 2px solid black;
    text-align: center;
    font-size: 33px;
}

button {
    width: 64px;
    height: 64px;
    background-image: url("../assets/icons/刷新.svg");
    background-repeat: no-repeat;
    background-size: 64px;
    background-color: aliceblue;
    border: none;
    cursor: pointer;
    margin: 10px;
}

</style>