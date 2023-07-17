<template>
  <div id="brand">
    <h1>品牌管理</h1>
    <el-table :data="brands" style="width: 100%" max-height="700">
      <el-table-column fixed prop="id" label="id" width="140px" />
      <el-table-column prop="name" label="name" />
      <el-table-column prop="remark" label="remark" />
      <el-table-column fixed="right" label="Operations">
        <template #default="scope">
          <el-button
            link
            type="primary"
            size="small"
            @click.prevent="deleteRow(scope.$index)"
          >
            Remove
          </el-button>
        </template>
      </el-table-column>
    </el-table>
    <!-- <el-button class="mt-4" style="width: 100%" @click="onAddItem"
      >Add Item</el-button
    > -->
  </div>

  <div id="model">
    <h1>型号管理</h1>
  </div>
</template>
  
  <script lang="ts" setup>
import { ref } from "vue";
import dayjs from "dayjs";
import { onBeforeMount } from "vue";
import axios from "axios";
import { ElMessage } from "element-plus";
import { ElTable } from "element-plus";

const props = defineProps({
  message: Object,
  carCompare: Array,
});

const emits = defineEmits(["addComCar"]);
var user_info = props.message as {
  id: number;
  username: string;
  password: string;
  monery: DoubleRange;
  manage: boolean;
};

var brands = ref([]);

onBeforeMount(() => {
  getBrands();
});

const getBrands = async () => {
  try {
    let ret = await axios.post("http://localhost:8080/getAllBrand");
    brands = ret.data;
  } catch (error) {
    ElMessage.error(error);
  }
};

const deleteRow = (index) => {
  brands.value.splice(index, 1);
};
</script>


<style scoped>
#brand,
#model {
  margin: 50px;
}
h1 {
  margin-bottom: 30px;
}
</style>
  