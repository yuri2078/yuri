<template>
  <el-container class="layout-container-demo" style="height: 100%">
    <el-main>
      <el-scrollbar>
        <el-table :data="cars" table-layout="auto" @row-click="showCarInfo">
          <el-table-column prop="id" label="id" width="140" align="center" />
          <el-table-column
            prop="brand_name"
            label="品牌"
            width="120"
            align="center"
          />
          <el-table-column prop="model_name" label="车型" align="center" />
          <el-table-column
            prop="mileage"
            label="里程数"
            sortable
            align="center"
          />
          <el-table-column prop="price" label="价格" sortable align="center" />
          <!-- <el-table-column prop="type_of_clutch" label="Address" /> -->
          <el-table-column
            prop="release_date"
            label="发布时间"
            sortable
            align="center"
          />
          <el-table-column align="left" #default="{ row }">
            <el-dropdown>
              <el-button type="success" plain>操作</el-button>
              <template #dropdown>
                <el-dropdown-menu>
                  <el-dropdown-item @click="addCollect(row)"
                    >收藏</el-dropdown-item
                  >
                  <el-dropdown-item @click="addCarCom(row)">加入对比</el-dropdown-item>
                  <el-dropdown-item @click="buyCar(row)">购买</el-dropdown-item>
                </el-dropdown-menu>
              </template>
            </el-dropdown>
          </el-table-column>
        </el-table>
      </el-scrollbar>
    </el-main>
    <el-footer>
      <el-descriptions title="详细信息" :column="3" border>
        <el-descriptions-item
          label="id"
          label-align="center"
          align="center"
          label-class-name="my-label"
          class-name="my-content"
          width="150px"
          >{{ cars[currentCar].id }}</el-descriptions-item
        >
        <el-descriptions-item label="品牌" label-align="center" align="center"
          ><el-tag size="large">{{
            cars[currentCar].brand_name
          }}</el-tag></el-descriptions-item
        >
        <el-descriptions-item
          label="车辆型号"
          label-align="center"
          align="center"
          ><el-tag size="large">{{
            cars[currentCar].model_name
          }}</el-tag></el-descriptions-item
        >
        <el-descriptions-item
          label="里程数"
          span="1"
          label-align="center"
          align="center"
        >
          {{ cars[currentCar].mileage }}
        </el-descriptions-item>
        <el-descriptions-item label="价格" label-align="center" align="center">
          {{ cars[currentCar].price }}
        </el-descriptions-item>
        <el-descriptions-item label="排量" label-align="center" align="center">
          {{ cars[currentCar].displacement }}
        </el-descriptions-item>
        <el-descriptions-item
          label="离合器类型"
          label-align="center"
          align="center"
          span="3"
        >
          {{ cars[currentCar].type_of_clutch }}
        </el-descriptions-item>
        <el-descriptions-item
          label="上牌时间"
          span="3"
          label-align="center"
          align="center"
        >
          {{ cars[currentCar].registration_date }}
        </el-descriptions-item>
        <el-descriptions-item
          label="登记时间"
          span="3"
          label-align="center"
          align="center"
        >
          {{ cars[currentCar].release_date }}
        </el-descriptions-item>
      </el-descriptions>
    </el-footer>
  </el-container>
</template>

<script lang="ts" setup>
import { ref, onBeforeMount } from "vue";
import { Menu as IconMenu, Setting } from "@element-plus/icons-vue";
import axios from "axios";
import { ElMessage, emitChangeFn } from "element-plus";
import { Message } from "element-plus";

const emits = defineEmits(['addComCar']);

const props = defineProps({
  message: Object,
  carCompare:Array
});

var user_info = props.message as {
  id: number,
  username: string,
  password: string,
  monery: DoubleRange,
  manage:boolean
};


var cars = ref([
  {
    id: 1,
    brand_name: "奥迪",
    model_name: "奥迪A4L",
    displacement: 2.0,
    price: 250000.0,
    release_date: "2019-12-01",
    mileage: 10000.0,
    registration_date: "2020-01-01",
    type_of_clutch: "自动",
  },
]);

var currentCar = ref(0);

onBeforeMount(() => {
  getCars();
});

const addCarCom = (row) => {
  emits("addComCar", row);
};

const getCars = async () => {
  try {
    let get = await axios.get("http://localhost:8080/getAllCarInfo");
    cars.value = get.data;
  } catch (error) {
    ElMessage.error(error);
  }
};

const showCarInfo = (row) => {
  for (let index = 0; index < cars.value.length; index++) {
    if (row.id == cars.value[index].id) {
      currentCar.value = index;
      break;
    }
  }
};

const addCollect = async (row) => {
  if (user_info.id === -1) {
    ElMessage.error("请先登陆");
    return;
  }

  try {
    let get = await axios.post("http://localhost:8080/addCollect", {
      user_id: user_info.id,
      car_id: row.id
    });
    
    if (get.data == -1) {
      ElMessage.info("已经收藏过了哦!");
      return;
    } else if (get.data == 1) {
      ElMessage.success("收藏成功!");
    } else {
      ElMessage.error("收藏失败!");
    }
  } catch (error) {
    ElMessage.error(error);
  }
};

const buyCar = async (row) => {
  if (user_info.id === -1) {
    ElMessage.error("请先登陆");
    return;
  }

  try {
    let get = await axios.post("http://localhost:8080/addStorehouse", {
      user_id: user_info.id,
      car_id: row.id
    });
    
    if (get.data == -1) {
      ElMessage.info("已经购买过了哦!");
      return;
    } else if (get.data == 1) {
      ElMessage.success("购买成功!");
    } else {
      ElMessage.error("购买失败!");
    }
  } catch (error) {
    ElMessage.error(error);
  }
};


</script>



  
<style scoped>
.layout-container-demo .el-header {
  position: relative;
  background-color: var(--el-color-primary-light-7);
  color: var(--el-text-color-primary);
}
.layout-container-demo .el-aside {
  color: var(--el-text-color-primary);
  background: aliceblue;
}
.layout-container-demo .el-menu {
  border-right: none;
}
.layout-container-demo .el-main {
  padding: 0;
}

.layout-container-demo .toolbar {
  display: inline-flex;
  align-items: center;
  justify-content: center;
  height: 100%;
  right: 20px;
}
.el-main {
  padding: 0 !important;
}

.el-footer {
  /* background-color: gray; */
  height: auto;
  padding: 32px;
}
</style>
  