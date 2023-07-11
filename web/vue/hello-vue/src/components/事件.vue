<template>
	<h2>内联事件</h2>
	<p>count -> {{ count }}</p>
	<button @click="count++">点我</button>
	<br />
	<h2>函数</h2>
    <p>count -> {{ count }}</p>
	<button @click="addCount">点我</button>
</template>

<script>
export default {
	data() {
		return {
			count: 0
		};
    },
    methods: {
        addCount() {
            this.count++;
            console.log("count + 1");
        }
    }
};
</script>