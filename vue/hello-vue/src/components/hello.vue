<template>
  <p> {{ yuri }} </p>
  <p> {{ OK ? 'yes' : 'no' }}</p>
  <p> {{ }} </p>
  <p v-html="a"></p>
  <div v-bind:id="id">
    <p>
      {{ yuri }}
    </p>
  </div>
</template>
  
<script>
export default {
  data() {
    return {
      yuri: "yuri is yes",
      OK: true,
      message: "message",
      a: "<a href = 'www.baidu.com'>百度</a>",
      id: "yuri"
    }
  }
}
</script>
  
  
  