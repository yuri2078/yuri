#!/bin/bash

format() {
    mkfs.fat -F32 /dev/nvme0n1p2 &&
    mkfs.ext4 /dev/nvme0n1p1 &&
    mkswap /dev/nvme0n1p4 &&
    swapon /dev/nvme0n1p4 &&
    mkfs.ext4 /dev/nvme0n1p3 && 
    mount /dev/nvme0n1p1 /mnt &&
    mkdir -p /mnt/boot/efi &&
    mount /dev/nvme0n1p2 /mnt/boot/efi &&
    mkdir /mnt/home &&
    mount /dev/nvme0n1p3 /mnt/home 
}

sort() {
    reflector --country China --age 72 --sort rate --protocol https --save /etc/pacman.d/mirrorlist

    if [ $? -ne 0 ]; then
        sudo cp mirrorlist /etc/pacman.d/mirrorlist
    fi
}

linux() {
    pacstrap /mnt base linux-lts linux-lts-headers linux-firmware base-devel &&
    genfstab -U /mnt >> /mnt/etc/fstab &&
    arch-chroot /mnt
}

time() {
    pacman -S neovim iwd ttf-dejavu sudo bluez usbmuxd networkmanager dhcpcd wqy-zenhei ntfs-3g &&
    ln -s /bin/nvim /bin/vim &&
    ln -s /bin/nvim /bin/vi &&
    ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime &&
    hwclock --systohc 
}

config() {
    sudo cp locale.gen /etc/locale.gen &&
    echo yuri >> /etc/hostname &&
    sudo cp hosts /etc/hosts  &&
    pacman -S grub efibootmgr &&
    grub-install /dev/nvme0n1 &&
    grub-mkconfig -o /boot/grub/grub.cfg 
}

active() {
    systemctl start iwd.service &&
    systemctl enable iwd.service &&
    systemctl start systemd-resolved.service &&
    systemctl enable systemd-resolved.service &&
    systemctl enable bluetooth.service &&
    systemctl enable NetworkManager &&
    systemctl enable dhcpcd &&
    sudo cp main.conf /etc/iwd/main.conf &&
    sudo cp NetworkManager.conf /etc/NetworkManager/NetworkManager.conf 
}



# 获取传递给脚本的第一个参数
function_name=$1

# 根据函数名调用相应的函数
case $function_name in
    "format")
        format
        ;;
    "sort")
        sort
        ;;
    "linux")
        linux
        ;;
    "time")
        time
        ;;
    "config")
        config
        ;;
    "active")
        active
        ;;
    *)
        echo "is not 'format sort linux time config active '!!!"
        ;;
esac
