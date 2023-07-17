<template>
  <h1>我的收藏</h1>
  switch parent border: <el-switch v-model="parentBorder" /> switch child
  border: <el-switch v-model="childBorder" />
  <el-table :data="collects" :border="parentBorder" style="width: 100%" empty-text="您没有收藏任何车辆">
    <el-table-column type="expand">
      <template #default="props">
        <el-descriptions title="详细信息" :column="3" border>
          <el-descriptions-item
            label="id"
            label-align="center"
            align="center"
            label-class-name="my-label"
            class-name="my-content"
            width="150px"
            >{{ props.row.id }}</el-descriptions-item
          >
          <el-descriptions-item label="品牌" label-align="center" align="center"
            ><el-tag size="large">{{
              props.row.brand_name
            }}</el-tag></el-descriptions-item
          >
          <el-descriptions-item
            label="车辆型号"
            label-align="center"
            align="center"
            ><el-tag size="large">{{
              props.row.model_name
            }}</el-tag></el-descriptions-item
          >
          <el-descriptions-item
            label="里程数"
            span="1"
            label-align="center"
            align="center"
          >
            {{ props.row.mileage }}
          </el-descriptions-item>
          <el-descriptions-item
            label="价格"
            label-align="center"
            align="center"
          >
            {{ props.row.price }}
          </el-descriptions-item>
          <el-descriptions-item
            label="排量"
            label-align="center"
            align="center"
          >
            {{ props.row.displacement }}
          </el-descriptions-item>
          <el-descriptions-item
            label="离合器类型"
            label-align="center"
            align="center"
            span="3"
          >
            {{ props.row.type_of_clutch }}
          </el-descriptions-item>
          <el-descriptions-item
            label="上牌时间"
            span="3"
            label-align="center"
            align="center"
          >
            {{ props.row.registration_date }}
          </el-descriptions-item>
          <el-descriptions-item
            label="登记时间"
            span="3"
            label-align="center"
            align="center"
          >
            {{ props.row.release_date }}
          </el-descriptions-item>
        </el-descriptions>
      </template>
    </el-table-column>
    <el-table-column label="车辆id" prop="id" />
    <el-table-column prop="brand_name" label="品牌" />
    <el-table-column prop="model_name" label="车型" />
    <el-table-column label="登记时间" prop="registration_date" />
    <el-table-column fixed="right" label="Operations" width="150" #default="{row}">
        <el-button
          link
          type="primary"
          size="small"
          @click.prevent="deleteRow(row, 'delCollect')"
        >
          Remove
        </el-button>
    </el-table-column>
  </el-table>
  <h1>我的仓库</h1>
  <el-table :data="storehouse" :border="parentBorder" style="width: 100%" empty-text="您没有购买任何车辆!">
    <el-table-column type="expand">
      <template #default="props">
        <el-descriptions title="详细信息" :column="3" border>
          <el-descriptions-item
            label="id"
            label-align="center"
            align="center"
            label-class-name="my-label"
            class-name="my-content"
            width="150px"
            >{{ props.row.id }}</el-descriptions-item
          >
          <el-descriptions-item label="品牌" label-align="center" align="center"
            ><el-tag size="large">{{
              props.row.brand_name
            }}</el-tag></el-descriptions-item
          >
          <el-descriptions-item
            label="车辆型号"
            label-align="center"
            align="center"
            ><el-tag size="large">{{
              props.row.model_name
            }}</el-tag></el-descriptions-item
          >
          <el-descriptions-item
            label="里程数"
            span="1"
            label-align="center"
            align="center"
          >
            {{ props.row.mileage }}
          </el-descriptions-item>
          <el-descriptions-item
            label="价格"
            label-align="center"
            align="center"
          >
            {{ props.row.price }}
          </el-descriptions-item>
          <el-descriptions-item
            label="排量"
            label-align="center"
            align="center"
          >
            {{ props.row.displacement }}
          </el-descriptions-item>
          <el-descriptions-item
            label="离合器类型"
            label-align="center"
            align="center"
            span="3"
          >
            {{ props.row.type_of_clutch }}
          </el-descriptions-item>
          <el-descriptions-item
            label="上牌时间"
            span="3"
            label-align="center"
            align="center"
          >
            {{ props.row.registration_date }}
          </el-descriptions-item>
          <el-descriptions-item
            label="登记时间"
            span="3"
            label-align="center"
            align="center"
          >
            {{ props.row.release_date }}
          </el-descriptions-item>
        </el-descriptions>
      </template>
    </el-table-column>
    <el-table-column label="车辆id" prop="id" />
    <el-table-column prop="brand_name" label="品牌" />
    <el-table-column prop="model_name" label="车型" />
    <el-table-column label="登记时间" prop="registration_date" />
    <el-table-column fixed="right" label="Operations" width="120" #default="{ row }">
        <el-button
          link
          type="primary"
          size="small"
          @click.prevent="deleteRow(row, 'delStorehouse')"
        >
          Remove
        </el-button>
    </el-table-column>
  </el-table>
</template>
  
<script lang="ts" setup>
import { ref } from "vue";
import { onBeforeMount } from "vue";
import axios from "axios";
import { ElMessage } from "element-plus";

// 声明和接收父组件传递的 props
const props = defineProps({
  message: Object,
  carCompare:Array
});

const emits = defineEmits(['addComCar']);

var user_info = props.message as {
  id: number,
  username: string,
  password: string,
  monery: DoubleRange,
  manage:boolean
};

var count = ref();
var collects = ref([]);
var storehouse = ref([]);

onBeforeMount(() => {
  getCollects();
  getStorehouse();
});

const deleteRow = async (row,url) => {
  try {
    let get = await axios.post("http://localhost:8080/" + url, {
      user_id: user_info.id,
      car_id: row.id
    });
    if (get.data == -1) {
      ElMessage.info("数据库中没有该收藏!");
      return;
    } else if (get.data == 1) {
      getCollects();
      getStorehouse();
      ElMessage.success("删除成功!");
    } else {
      ElMessage.error("删除失败!");
    }
  } catch (error) {
    ElMessage.error(error);
  }
}

const getCollects = async () => {
  try {
    let get = await axios.get("http://localhost:8080/getAllCollectInfo", {
      params: {
        id: user_info.id,
      },
    });
    collects.value = get.data;
  } catch (error) {
    ElMessage.error(error);
  }
  
};

const getStorehouse = async () => {
  try {
    let get = await axios.get("http://localhost:8080/getStorehouse", {
      params: {
        id: user_info.id,
      },
    });
    storehouse.value = get.data;
  } catch (error) {
    ElMessage.error(error);
  }
}

const parentBorder = ref(false);
const childBorder = ref(false);
</script>

<style scoped>
h1, .el-talbe {
  margin: 20px 0px;
}

.el-switch {
  margin: 10px 30px;
}

</style>
  