import { createRouter, createWebHashHistory } from "vue-router"

import hello from "./components/hello.vue"
import test from "./components/test.vue"
import login from "./components/login.vue"
import student from "./components/student.vue"
import userinfo from "./components/userinfo.vue"
import { compile } from "vue"

const router = createRouter({
    history: createWebHashHistory(),
    routes: [
        {
            path: '/',
            component: userinfo,
        },
        {
            path: '/test',
            component:test
        },
        {
            path: '/hello',
            component:hello
        },
        {
            path: '/student',
            component: student,
            children: [
                {
                    path: '/userinfo',
                    component:userinfo
                }
                
            ]
        },
        {
            path: '/student/userinfo',
            component:userinfo
            
        }
    ]
});

export default router;