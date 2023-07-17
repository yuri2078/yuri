<template>
    <div>
        <h1>最新二手车信息</h1>
        <button @click="getData"></button>
        <table v-if="cars !== null">
            <tr>
                <th v-for="(value,key,index) in cars[0]" :key="index">{{ key }}</th>
            </tr>

            <tr v-for="car in cars" :key="car.id">
                <td v-for="(value, key, index) in car" :key="index">{{ value }}</td>
            </tr>


        </table>
        
    </div>
	
</template>

<script>
export default {
    emits :['myemits'],
	data() {
        return {
            cars:[{"id":1,"displacement":2.0,"registration_date":"2020-01-01","price":250000.0,"mileage":10000.0,"type_of_clutch":"自动","release_date":"2019-12-01","model_id":1},{"id":2,"displacement":2.5,"registration_date":"2019-05-15","price":350000.0,"mileage":20000.0,"type_of_clutch":"自动","release_date":"2019-04-01","model_id":2},{"id":3,"displacement":2.0,"registration_date":"2018-07-10","price":280000.0,"mileage":15000.0,"type_of_clutch":"自动","release_date":"2018-06-01","model_id":3},{"id":4,"displacement":3.0,"registration_date":"2019-11-20","price":450000.0,"mileage":18000.0,"type_of_clutch":"自动","release_date":"2019-10-01","model_id":4},{"id":5,"displacement":2.0,"registration_date":"2017-09-05","price":220000.0,"mileage":30000.0,"type_of_clutch":"自动","release_date":"2017-08-01","model_id":5},{"id":6,"displacement":2.5,"registration_date":"2016-03-12","price":320000.0,"mileage":25000.0,"type_of_clutch":"自动","release_date":"2016-02-01","model_id":6},{"id":7,"displacement":1.6,"registration_date":"2019-08-18","price":180000.0,"mileage":22000.0,"type_of_clutch":"自动","release_date":"2019-07-01","model_id":7},{"id":8,"displacement":2.0,"registration_date":"2018-12-05","price":260000.0,"mileage":19000.0,"type_of_clutch":"自动","release_date":"2018-11-01","model_id":8},{"id":9,"displacement":1.5,"registration_date":"2017-04-25","price":150000.0,"mileage":35000.0,"type_of_clutch":"自动","release_date":"2017-03-01","model_id":9},{"id":10,"displacement":2.0,"registration_date":"2019-10-10","price":240000.0,"mileage":28000.0,"type_of_clutch":"自动","release_date":"2019-09-01","model_id":10},{"id":11,"displacement":1.6,"registration_date":"2016-06-08","price":130000.0,"mileage":40000.0,"type_of_clutch":"自动","release_date":"2016-05-01","model_id":11},{"id":12,"displacement":2.8,"registration_date":"2015-01-15","price":380000.0,"mileage":32000.0,"type_of_clutch":"自动","release_date":"2014-12-01","model_id":12},{"id":13,"displacement":1.8,"registration_date":"2018-09-20","price":120000.0,"mileage":40000.0,"type_of_clutch":"手动","release_date":"2018-08-01","model_id":7},{"id":14,"displacement":2.2,"registration_date":"2017-11-05","price":180000.0,"mileage":32000.0,"type_of_clutch":"手动","release_date":"2017-10-01","model_id":8},{"id":15,"displacement":1.4,"registration_date":"2016-05-15","price":90000.0,"mileage":50000.0,"type_of_clutch":"手动","release_date":"2016-04-01","model_id":9},{"id":16,"displacement":1.6,"registration_date":"2019-10-25","price":110000.0,"mileage":45000.0,"type_of_clutch":"手动","release_date":"2019-09-01","model_id":10},{"id":17,"displacement":1.6,"registration_date":"2016-07-12","price":80000.0,"mileage":60000.0,"type_of_clutch":"手动","release_date":"2016-06-01","model_id":11},{"id":18,"displacement":2.0,"registration_date":"2014-12-28","price":150000.0,"mileage":55000.0,"type_of_clutch":"手动","release_date":"2014-11-01","model_id":12},{"id":19,"displacement":1.5,"registration_date":"2019-06-08","price":95000.0,"mileage":48000.0,"type_of_clutch":"手动","release_date":"2019-05-01","model_id":7},{"id":20,"displacement":1.8,"registration_date":"2018-08-15","price":130000.0,"mileage":42000.0,"type_of_clutch":"手动","release_date":"2018-07-01","model_id":8},{"id":21,"displacement":1.6,"registration_date":"2017-02-25","price":70000.0,"mileage":55000.0,"type_of_clutch":"手动","release_date":"2017-01-01","model_id":9},{"id":22,"displacement":1.4,"registration_date":"2019-09-10","price":100000.0,"mileage":50000.0,"type_of_clutch":"手动","release_date":"2019-08-01","model_id":10}],
            message:''
		};
    },

    created() {
        // this.getData();
    },
    methods: {
        async getData() {
            try {
                let get = await axios.get("http://localhost:8080/getAllCars", null);
                console.log(get.data);
                this.cars = get.data
            } catch (error) {
                this.cars = null;
                console.log(error);
            }
        }
    }
};
import axios from 'axios';
</script>

<style scoped>

* {
    padding: 0px;
    margin: 0px;
    box-sizing: border-box;
}

div {
    width:100%;
    height: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
}

h1 {
	text-align: center;
	font-size: 80px;
	color: grey;
}

table {
    /* border: 2px solid black; */
    width: 800px;
    height: 800px;
}

tr, td, th {
    border: 2px solid black;
    text-align: center;
    font-size: 33px;
}

button {
    width: 64px;
    height: 64px;
    background-image: url("../assets/icons/刷新.svg");
    background-repeat: no-repeat;
    background-size: 64px;
    background-color: aliceblue;
    border: none;
    cursor: pointer;
    margin: 10px;
}

</style>