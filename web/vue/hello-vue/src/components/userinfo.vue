<template>
    <div>
        <h1>学生信息管理</h1>
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
        getData() {
            axios.get("http://localhost:8080/findStudent", null,).then((response) => {
                console.log(response.data);
                if (response.data != null) {
                    this.students = response.data
                }
            }).catch((response) => { 
                console.log(response);
            });
            console.log("加载学生列表!");
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
    width: 1000px;
    height: 800px;
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

</style>