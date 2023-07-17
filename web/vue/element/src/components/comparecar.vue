<template>
  <el-table
    :data="cars"
    table-layout="auto"
    max-height="600px"
    ref="selections"
    @selection-change="selectChange"
    empty-text="请先添加车车!"
  >
    <el-table-column type="selection" width="100px"></el-table-column>
    <el-table-column prop="id" label="id" width="140" align="left" />
    <el-table-column prop="brand_name" label="品牌" width="120" align="left" />
    <el-table-column prop="model_name" label="车型" align="left" />
    <el-table-column prop="mileage" label="里程数" sortable align="left" />
    <el-table-column prop="price" label="价格" sortable align="left" />
    <!-- <el-table-column prop="type_of_clutch" label="Address" /> -->
    <el-table-column
      prop="release_date"
      label="发布时间"
      sortable
      align="left"
    />
    <el-table-column #default="{row}" >
      <el-button type="danger" icon=Delete circle @click="deleteRow(row)"  />
    </el-table-column>
  </el-table>
  <div id="select">
    <el-button type="primary" @click="cleanSelect">清除选择</el-button>
    <el-button type="primary" @click="startCom">开始对比</el-button>
  </div>

  <h1>详细对比</h1>

  <el-table :data="comCars" table-layout="auto" empty-text="请先选择车车!">
    <el-table-column prop="name" label="名称"></el-table-column>
    <el-table-column prop="data" label="数据" align="center">
      <template #default="{ row }">
        <div class="data" v-for="item in row.data" :key="item">{{ item }}</div>
      </template>
    </el-table-column>
  </el-table>
</template>

<script lang="ts" setup>
import { ref } from "vue";
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

var cars = ref([]);
var compares = ref([]);
var comCars = ref([]);

onBeforeMount(() => {
  getCars(props.carCompare);
});

const getCars = (carCompare) => {
  cars.value = carCompare;
};

const getComCars = (cars) => {
  comCars.value! = cars;
};

const selectChange = (select) => {
  compares.value! = select;
};

const selections = ref<InstanceType<typeof ElTable>>();

const cleanSelect = () => {
  selections.value!.clearSelection();
};

const deleteRow = (row) => {
  for (let i = 0; i < cars.value.length; i++) {
    let car = cars.value[i] as { id: Number };
    if (row.id == car.id) {
      cars.value.splice(i, 1);
      ElMessage.success("删除成功!");
      return;
    }
  }
  
};

const startCom = () => {
  let yuri = [
    { name: "品牌", data: [] as string[] },
    { name: "车型", data: [] as string[] },
    { name: "价格", data: [] as string[] },
    { name: "排量", data: [] as string[] },
    { name: "里程数", data: [] as string[] },
    { name: "离合器", data: [] as string[] },
    { name: "上牌时间", data: [] as string[] },
  ];
  for (let index = 0; index < compares.value.length; index++) {
    let car = compares.value[index] as {
      brand_name: string;
      model_name: string;
      price: string;
      displacement: string;
      mileage: string;
      type_of_clutch: string;
      registration_date: string;
    };

    yuri[0].data.push(car.brand_name);
    yuri[1].data.push(car.model_name);
    yuri[2].data.push(car.price);
    yuri[3].data.push(car.displacement);
    yuri[4].data.push(car.mileage);
    yuri[5].data.push(car.type_of_clutch);
    yuri[6].data.push(car.registration_date);
  }
  
  getComCars(yuri);
};
</script>


<style scoped>
#select {
  width: 100%;
  height: 50px;
  display: flex;
  align-items: center;
  justify-content: center;
}

#select .el-button {
  margin-top: 50px;
  width: 200px;
}

.data {
  display: inline-block;
  width: 200px;
  /* background-color: aliceblue; */
  text-align: center;
  margin-right: 40px;
}

h1 {
  width: 100%;
  height: 80px;
  margin: 30px 0px;
  font-size: 40px;
  /* text-align: center; */
}
</style>