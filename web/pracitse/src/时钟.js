let hour = document.getElementById("hour");
let minute = document.getElementById("minute");
let second = document.getElementById("second");
let date = new Date;
hour.style.transform = `rotate(${date.getHours() * 30}deg)`;
minute.style.transform = `rotate(${date.getMinutes() * 6}deg)`;
second.style.transform = `rotate(${date.getSeconds() * 6}deg)`;

setInterval(() => {
    let date = new Date;
    hour.style.transform = `rotate(${date.getHours() * 30}deg)`;
    minute.style.transform = `rotate(${date.getMinutes() * 6}deg)`;
    second.style.transform = `rotate(${date.getSeconds() * 6}deg)`;
}, 1000);