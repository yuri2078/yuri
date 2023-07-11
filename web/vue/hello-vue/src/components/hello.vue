<template>
  <p> {{ yuri }} </p>
  <p> {{ OK ? 'yes' : 'no' }}</p>
  <p> {{ }} </p>
  <P v-html="a"></P>
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
  
  
  