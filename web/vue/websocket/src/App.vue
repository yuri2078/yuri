<template>
  <el-upload
    class="upload-demo"
    drag
    action="http://192.168.1.164:2078/file"
    multiple
  >
    <el-icon class="el-icon--upload"><upload-filled /></el-icon>
    <div class="el-upload__text">
      Drop file here or <em>click to upload</em>
    </div>
    <template #tip>
      <div class="el-upload__tip">
        jpg/png files with a size less than 500kb
      </div>
    </template>
  </el-upload>
  <div>
    <a href="http://192.168.1.164:2078/download" download>
    <el-button type="success" :icon="Check" circle /></a>

  </div>
</template>

<script setup lang="ts">
import { UploadFilled, Check } from '@element-plus/icons-vue'

const download = () => {

}
</script>
