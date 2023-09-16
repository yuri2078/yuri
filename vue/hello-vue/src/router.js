import { createRouter, createWebHashHistory } from "vue-router"

import hello from "./components/hello.vue"
import test from "./components/test.vue"
import login from "./components/login.vue"
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
            component: userinfo,
        },
        {
            path: '/student/0',
            component:userinfo
        },
        {
            path: '/student/1',
            component:hello
        },
        {
            path: '/student/2',
            component:test
        },
        {
            path: '/student/3',
            component:hello
        },
        {
            path: '/student/4',
            component:hello
        },
        {
            path: '/student/5',
            component:hello
        },
        {
            path: '/student/6',
            component:hello
        },
        {
            path: '/student/7',
            component:hello
        },
        {
            path: '/student/8',
            component:hello
        }
    ]
});

export default router;