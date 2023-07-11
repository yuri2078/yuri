<template>
  <p>{{ msg }}</p>
  <div v-if="flag">v-if测试</div>
  <div v-if="word === 'A'">A</div>
  <div v-else-if="word === 'B'">B</div>
  <div v-else-if="word === 'C'">C</div>
  <div v-else>NOT ABC</div>
  <div v-show="flag">v-show测试</div>
  <!-- v-show 基于 css 的 display 属性 -->
  
</template>


<script>
export default {
  data() {
    return {
      msg: "v-if v-else 测试",
      flag: true,
      word: "D"
    }
  }
}
</script>