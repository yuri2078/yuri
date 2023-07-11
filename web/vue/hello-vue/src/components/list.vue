<template>
    <h2>列表渲染测试</h2>
    <h3>没有index 渲染</h3>
    <table>
        <tr>
            <td v-for="name in names" :key="name.indexOf">{{ name }}</td>
        </tr>
        <tr>
            <td v-for="(name, index) in names" :key="name.indexOf">index -> {{ index }} value -> {{ name }}</td>
        </tr>
    </table>

    <h2>对象数组遍历</h2>
    <div v-for="teacher in teachers" :key="teacher.indexOf">
       <p v-for="(value, index, key) in teacher" :key="key">
            value -> {{ value }} index -> {{ index }} key -> {{ key }}
       </p>
    </div>
</template>

<script>
export default {
	data() {
		return {
			names: ['yuri', 'is', 'yes'],
            teachers: [
                {
                    name: "chinese",
                    age: 20,
                },
                {
                    name: "english",
                    age : 20
                }
            ],
            class: {
                classname: "iostream",
                parent:"ostream"
            }
		};
	}
};
</script>