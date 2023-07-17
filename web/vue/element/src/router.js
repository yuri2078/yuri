import { createRouter, createWebHashHistory } from "vue-router"
import userinfo from "./components/userinfo.vue"
import carsinfos from "./components/carsinfos.vue"
import page3 from "./components/page3.vue"
import page4 from "./components/page4.vue"
import page5 from "./components/page5.vue"
import mycollect from "./components/mycollect.vue"
import comparecar from "./components/comparecar.vue"
import manager from "./components/manager.vue"

const router = createRouter({
    history: createWebHashHistory(),
    routes: [
        {
            path: '/',
            component: carsinfos,
            props: true
        },
        {
            path: '/student/0',
            component: carsinfos,
            props: true
        },
        {
            path: '/student/1',
            component: mycollect,
            props: true
        },
        {
            path: '/student/2',
            component: comparecar,
            props: true
        },
        {
            path: '/student/3',
            component: manager,
            props: true
        },
        {
            path: '/student/4',
            component: page5,
            props: true
        },
        {
            path: '/student/5',
            component:mycollect
        }
    ]
});

export default router;