import { d as n, r as c, b as l, i as r, f as p, w as i, l as a, t as _, F as u, a as d, E as f, e as m, g as h } from "./index-7fce9f59.js"; const x = a("h1", null, "cpp请求测试", -1), N = n({ __name: "cpp", setup(g) { const e = c(0), o = async () => { try { let t = await d.post("http://localhost:2078/"); e.value = t.data } catch (t) { f.error(t) } }; return (t, v) => { const s = l("el-button"); return m(), r(u, null, [x, p(s, { onClick: o }, { default: i(() => [h("你好")]), _: 1 }), a("h2", null, _(e.value), 1)], 64) } } }); export { N as default };
