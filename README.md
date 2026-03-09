<div align="center">

```
    ██████╗  ██████╗ ██████╗ ███╗   ██╗██████╗ ██████╗ ███████╗██████╗  ██████╗  ██████╗ ████████╗
    ██╔══██╗██╔═══██╗██╔══██╗████╗  ██║╚════██╗██╔══██╗██╔════╝██╔══██╗██╔═══██╗██╔═══██╗╚══██╔══╝
    ██████╔╝██║   ██║██████╔╝██╔██╗ ██║ █████╔╝██████╔╝█████╗  ██████╔╝██║   ██║██║   ██║   ██║   
    ██╔══██╗██║   ██║██╔══██╗██║╚██╗██║██╔═══╝ ██╔══██╗██╔══╝  ██╔══██╗██║   ██║██║   ██║   ██║   
    ██████╔╝╚██████╔╝██║  ██║██║ ╚████║███████╗██████╔╝███████╗██║  ██║╚██████╔╝╚██████╔╝   ██║   
    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝    ╚═╝   
```

<img src="https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Debian-12-A81D33?style=for-the-badge&logo=debian&logoColor=white"/>
<img src="https://img.shields.io/badge/Score-125%2F100-brightgreen?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Status-Finished-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Language-Shell-89e051?style=for-the-badge&logo=gnu-bash&logoColor=white"/>

<br/>

> *"The more that you read, the more things you will know. The more that you learn, the more places you'll go."*

**A complete, step-by-step guide to the Born2beRoot project — system administration, virtualization, and Linux hardening at 42 School.**

[🚀 Getting Started](#-getting-started) · [⚙️ Installation](#%EF%B8%8F-vm-installation) · [🔐 Security](#-security-configuration) · [📊 Monitoring](#-monitoring-script) · [❓ Defense FAQ](#-defense-faq)

</div>

---

## 📖 Table of Contents

<details>
<summary>Click to expand</summary>

- [📌 About the Project](#-about-the-project)
- [🧠 Key Concepts](#-key-concepts)
- [🚀 Getting Started](#-getting-started)
- [⚙️ VM Installation](#%EF%B8%8F-vm-installation)
- [🧱 Disk Partitioning with LVM](#-disk-partitioning-with-lvm)
- [🌐 Network & Hostname](#-network--hostname)
- [👤 User & Group Management](#-user--group-management)
- [🔐 Security Configuration](#-security-configuration)
  - [🛡️ sudo Setup](#%EF%B8%8F-sudo-setup)
  - [🔑 Password Policy](#-password-policy)
  - [🧱 UFW Firewall](#-ufw-firewall)
  - [🔒 SSH Configuration](#-ssh-configuration)
  - [⚠️ AppArmor](#%EF%B8%8F-apparmor)
- [📊 Monitoring Script](#-monitoring-script)
- [🌟 Bonus Part](#-bonus-part)
  - [💡 WordPress Setup](#-wordpress-setup)
  - [⚡ Lighttpd](#-lighttpd)
  - [🐬 MariaDB](#-mariadb)
  - [🐘 PHP](#-php)
  - [🎁 Extra Service: Fail2ban](#-extra-service-fail2ban)
- [❓ Defense FAQ](#-defense-faq)
- [📚 Resources](#-resources)

</details>

---

## 📌 About the Project

**Born2beRoot** is a 42 School system administration project that introduces students to the world of **virtualization**. The goal is to set up a **Debian** (or Rocky Linux) server virtual machine from scratch, hardening it with strict security policies.

### 🎯 Objectives

| Goal | Description |
|------|-------------|
| 🖥️ Virtualization | Create and configure a VM using VirtualBox or UTM |
| 🐧 Linux | Install and configure a minimal Debian server |
| 🔐 Security | Implement password policies, sudo rules, SSH, UFW |
| 📊 Monitoring | Write a bash script that broadcasts system info |
| 🌐 Bonus | Host a WordPress site with Lighttpd, MariaDB, PHP |

---

## 🧠 Key Concepts

Before diving in, make sure you understand these concepts — **you'll be asked about them in your defense**.

<details>
<summary>🖥️ <strong>What is a Virtual Machine?</strong></summary>

A **Virtual Machine (VM)** is software that emulates a physical computer. It runs an operating system (guest OS) inside another operating system (host OS). VMs use a **hypervisor** (like VirtualBox) to manage resources.

**Advantages:**
- Isolation from host system
- Snapshots and rollback
- Resource efficiency
- Safe environment for testing

</details>

<details>
<summary>🐧 <strong>Why Debian?</strong></summary>

**Debian** is a rock-solid, community-driven Linux distribution known for:
- Stability and long support cycles
- Minimal base install (perfect for servers)
- Huge package ecosystem (`apt`)
- No corporate ownership

Compared to **Rocky Linux** (RHEL-based), Debian uses `apt` instead of `dnf/yum`, and `AppArmor` instead of `SELinux`.

</details>

<details>
<summary>🧱 <strong>What is LVM?</strong></summary>

**Logical Volume Manager (LVM)** is an abstraction layer between physical disks and filesystems.

```
Physical Disk → Physical Volume (PV) → Volume Group (VG) → Logical Volume (LV) → Filesystem
```

**Benefits:**
- Resize partitions without unmounting
- Span volumes across multiple disks
- Snapshots for backups

</details>

<details>
<summary>🔑 <strong>What is AppArmor?</strong></summary>

**AppArmor** is a Linux security module that implements **Mandatory Access Control (MAC)**. It confines programs to a limited set of resources using profiles.

```bash
# Check AppArmor status
sudo aa-status
```

</details>

---

## 🚀 Getting Started

### 📋 Prerequisites

- **VirtualBox** 6.x or 7.x (or UTM on Apple Silicon)
- **Debian 12** ISO — [Download here](https://www.debian.org/download)
- At least **8GB disk space** (30GB+ for bonus)
- **RAM**: 1024 MB minimum

### 📥 Download Links

| Resource | Link |
|----------|------|
| VirtualBox | [virtualbox.org](https://www.virtualbox.org/wiki/Downloads) |
| Debian 12 ISO | [debian.org/download](https://www.debian.org/download) |
| Subject PDF | [42 born2beroot subject](https://cdn.intra.42.fr/pdf/pdf/119699/en.subject.pdf) |

---

## ⚙️ VM Installation

### Step 1 — Create a New VM in VirtualBox

```
New → Name: born2beroot → Type: Linux → Version: Debian (64-bit)
Memory: 1024 MB
Hard Disk: Create a virtual hard disk now → VDI → Dynamically allocated → 30.8 GB
```

> 💡 **Tip:** Store your VM inside your `sgoinfre` directory at 42 to avoid quota issues.

### Step 2 — Mount the ISO

```
Settings → Storage → Controller: IDE → Empty → Disk icon → Choose your Debian ISO
```

### Step 3 — Boot and Install Debian

Start the VM and follow these steps:

```
1. Select: Install (not graphical install)
2. Language: English
3. Country: Your country
4. Locale: en_US.UTF-8
5. Keyboard: your layout
```

---

## 🧱 Disk Partitioning with LVM

This is the **most important part** of the installation. Choose **manual** partitioning.

### 🗂️ Mandatory Partition Layout

```
sda
├── sda1     /boot       487M   (primary, ext2)
└── sda5     [encrypted] (logical, LVM)
    └── LVMGroup (Volume Group)
        ├── root        2.8G
        ├── swap        976M
        ├── home        3.8G
        ├── var         2.8G
        ├── srv         2.8G
        ├── tmp         2.8G
        └── var--log    3.8G
```

### Step-by-Step Partitioning

```
1. Select: Manual
2. Select your disk: SCSI1 (sda)
3. Create new empty partition table: YES

── Create /boot ──────────────────────────────────────
4. Select FREE SPACE → New partition
5. Size: 500M
6. Type: Primary
7. Location: Beginning
8. Use as: Ext2 file system
9. Mount point: /boot
10. Done setting up the partition

── Create Encrypted Partition ────────────────────────
11. Select FREE SPACE → New partition
12. Size: max (remaining)
13. Type: Logical
14. Use as: physical volume for encryption
15. Done → Finish

── Configure Encryption ──────────────────────────────
16. Configure encrypted volumes → YES
17. Create encrypted volumes → select /dev/sda5
18. Done → Finish → YES
19. Set encryption passphrase (REMEMBER THIS!)

── Configure LVM ─────────────────────────────────────
20. Configure the Logical Volume Manager → YES
21. Create volume group → LVMGroup → select encrypted device
22. Create logical volumes:
    - root   → 2.8G
    - swap   → 976M
    - home   → 3.8G
    - var    → 2.8G
    - srv    → 2.8G
    - tmp    → 2.8G
    - var-log→ 3.8G

── Assign Filesystems ────────────────────────────────
23. For each LV, set:
    - root, home, var, srv, tmp, var-log → Ext4, correct mount point
    - swap → swap area
24. Finish partitioning and write changes to disk → YES
```

### Verify Partition Setup

```bash
lsblk
```

Expected output:
```
NAME                    MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINT
sda                       8:0    0 30.8G  0 disk
├─sda1                    8:1    0  487M  0 part  /boot
├─sda2                    8:2    0    1K  0 part
└─sda5                    8:5    0 30.3G  0 part
  └─sda5_crypt          254:0    0 30.3G  0 crypt
    ├─LVMGroup-root     254:1    0  2.8G  0 lvm   /
    ├─LVMGroup-swap     254:2    0  976M  0 lvm   [SWAP]
    ├─LVMGroup-home     254:3    0  3.8G  0 lvm   /home
    ├─LVMGroup-var      254:4    0  2.8G  0 lvm   /var
    ├─LVMGroup-srv      254:5    0  2.8G  0 lvm   /srv
    ├─LVMGroup-tmp      254:6    0  2.8G  0 lvm   /tmp
    └─LVMGroup-var--log 254:7    0  3.8G  0 lvm   /var/log
```

---

## 🌐 Network & Hostname

### Set Hostname

During installation, set hostname to `<your_login>42`.

To change it later:
```bash
sudo hostnamectl set-hostname <your_login>42
```

Verify:
```bash
hostnamectl
```

### Update `/etc/hosts`

```bash
sudo nano /etc/hosts
```

```
127.0.0.1   localhost
127.0.1.1   <your_login>42
```

---

## 👤 User & Group Management

### Create Required User

Your login user must be in both `sudo` and `user42` groups.

```bash
# Create user (done during install, but if needed:)
sudo adduser <your_login>

# Create user42 group
sudo groupadd user42

# Add user to groups
sudo usermod -aG sudo <your_login>
sudo usermod -aG user42 <your_login>
```

### Verify Group Membership

```bash
groups <your_login>
# Output: your_login : your_login sudo user42

# Or check with:
getent group sudo
getent group user42
```

### Useful User Commands

```bash
# List all users
cut -d: -f1 /etc/passwd

# List all groups
cut -d: -f1 /etc/group

# Delete a user
sudo userdel -r username

# Change user password
sudo passwd username

# Lock/unlock a user
sudo passwd -l username   # lock
sudo passwd -u username   # unlock
```

---

## 🔐 Security Configuration

### 🛡️ sudo Setup

#### Install sudo

```bash
su -
apt install sudo
```

#### Add User to sudo Group

```bash
sudo usermod -aG sudo <your_login>
# Log out and back in, then verify:
sudo whoami   # should print: root
```

#### Configure sudo Rules

```bash
sudo visudo
# Or edit directly:
sudo nano /etc/sudoers.d/sudoconfig
```

Add the following configuration:

```bash
# /etc/sudoers.d/sudoconfig

# Limit sudo authentication attempts to 3
Defaults        passwd_tries=3

# Custom error message for wrong password
Defaults        badpass_message="Wrong password. Try again, human."

# Log sudo input/output
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        log_input
Defaults        log_output
Defaults        iolog_dir="/var/log/sudo"

# Require TTY for sudo
Defaults        requiretty

# Restrict PATH for sudo commands
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

Create the sudo log directory:

```bash
sudo mkdir -p /var/log/sudo
sudo chmod 700 /var/log/sudo
```

---

### 🔑 Password Policy

#### Install Password Quality Library

```bash
sudo apt install libpam-pwquality
```

#### Configure Password Rules

Edit the PAM password config:

```bash
sudo nano /etc/pam.d/common-password
```

Find the line with `pam_pwquality.so` and replace it with:

```
password        requisite       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

| Option | Meaning |
|--------|---------|
| `minlen=10` | Minimum 10 characters |
| `ucredit=-1` | At least 1 uppercase letter |
| `dcredit=-1` | At least 1 digit |
| `maxrepeat=3` | No more than 3 consecutive identical chars |
| `reject_username` | Password cannot contain the username |
| `difok=7` | At least 7 chars different from old password |
| `enforce_for_root` | Apply rules to root too |

#### Configure Password Expiry

```bash
sudo nano /etc/login.defs
```

Set:
```bash
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

Apply to existing users (including root):

```bash
sudo chage -M 30 <your_login>
sudo chage -m 2 <your_login>
sudo chage -W 7 <your_login>

sudo chage -M 30 root
sudo chage -m 2 root
sudo chage -W 7 root
```

Verify:

```bash
sudo chage -l <your_login>
```

---

### 🧱 UFW Firewall

#### Install UFW

```bash
sudo apt install ufw
```

#### Enable and Configure

```bash
# Enable UFW
sudo ufw enable

# Allow SSH on port 4242
sudo ufw allow 4242

# Check status
sudo ufw status verbose
```

Expected output:
```
Status: active

To                         Action      From
--                         ------      ----
4242                       ALLOW IN    Anywhere
4242 (v6)                  ALLOW IN    Anywhere (v6)
```

#### Useful UFW Commands

```bash
sudo ufw status numbered     # show rules with numbers
sudo ufw delete <number>     # delete a rule
sudo ufw deny 80             # block port 80
sudo ufw reset               # reset all rules
```

---

### 🔒 SSH Configuration

#### Install SSH Server

```bash
sudo apt install openssh-server
```

#### Configure SSH

```bash
sudo nano /etc/ssh/sshd_config
```

Make these changes:

```bash
# Change port from 22 to 4242
Port 4242

# Disable root login via SSH
PermitRootLogin no

# Disable password auth (optional, for key-only login)
# PasswordAuthentication no
```

#### Restart SSH

```bash
sudo systemctl restart ssh
sudo systemctl status ssh
```

#### Connect from Host Machine

```bash
# In VirtualBox: Settings → Network → Advanced → Port Forwarding
# Add rule: Host Port 4242 → Guest Port 4242

# Then connect:
ssh <your_login>@127.0.0.1 -p 4242
```

---

### ⚠️ AppArmor

AppArmor should be active by default on Debian 12.

```bash
# Check status
sudo aa-status

# Verify it starts on boot
sudo systemctl status apparmor

# Enable if not active
sudo systemctl enable apparmor
sudo systemctl start apparmor
```

---

## 📊 Monitoring Script

Create `/usr/local/bin/monitoring.sh`:

```bash
sudo nano /usr/local/bin/monitoring.sh
```

```bash
#!/bin/bash

# ─── Colors ──────────────────────────────────────────────────────────────────
B="\033[1m"        # Bold
R="\033[0m"        # Reset
G="\033[0;32m"     # Green
Y="\033[0;33m"     # Yellow

# ─── System Info ─────────────────────────────────────────────────────────────

ARCH=$(uname -a)

PCPU=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
VCPU=$(nproc)

RAM_USED=$(free -m | awk '/^Mem:/ {print $3}')
RAM_TOTAL=$(free -m | awk '/^Mem:/ {print $2}')
RAM_PERCENT=$(free | awk '/^Mem:/ {printf("%.2f"), $3/$2*100}')

DISK_USED=$(df -BM / | awk 'NR==2 {print $3}' | tr -d M)
DISK_TOTAL=$(df -BG / | awk 'NR==2 {print $2}' | tr -d G)
DISK_PERCENT=$(df / | awk 'NR==2 {print $5}')

CPU_LOAD=$(top -bn1 | grep "^%Cpu" | awk '{printf "%.1f%%", $2 + $4}')

LAST_BOOT=$(who -b | awk '{print $3, $4}')

LVM_COUNT=$(lsblk | grep -c "lvm")
LVM_USE=$(if [ "$LVM_COUNT" -gt 0 ]; then echo "yes"; else echo "no"; fi)

TCP_CONN=$(ss -tn state established | tail -n +2 | wc -l)

USER_LOG=$(users | tr ' ' '\n' | sort -u | wc -l)

IP=$(hostname -I | awk '{print $1}')
MAC=$(ip link | grep "link/ether" | awk '{print $2}')

SUDO_LOG=$(journalctl _COMM=sudo 2>/dev/null | grep COMMAND | wc -l)

# ─── Output ──────────────────────────────────────────────────────────────────

wall "
╔══════════════════════════════════════════════════════════╗
║               🖥️  SYSTEM MONITORING REPORT               ║
╚══════════════════════════════════════════════════════════╝

  #Architecture    : $ARCH
  #CPU physical    : $PCPU
  #vCPU            : $VCPU
  #Memory Usage    : ${RAM_USED}/${RAM_TOTAL}MB (${RAM_PERCENT}%)
  #Disk Usage      : ${DISK_USED}/${DISK_TOTAL}GB (${DISK_PERCENT})
  #CPU load        : $CPU_LOAD
  #Last boot       : $LAST_BOOT
  #LVM use         : $LVM_USE
  #Connections TCP : $TCP_CONN ESTABLISHED
  #User log        : $USER_LOG
  #Network         : IP $IP ($MAC)
  #Sudo            : $SUDO_LOG cmd

══════════════════════════════════════════════════════════"
```

Make it executable:

```bash
sudo chmod +x /usr/local/bin/monitoring.sh
```

### ⏰ Schedule with Cron

```bash
sudo crontab -e
```

Add this line to run every 10 minutes:

```bash
*/10 * * * * /usr/local/bin/monitoring.sh
```

#### Cron Syntax Reference

```
┌───────────── minute (0 - 59)
│ ┌───────────── hour (0 - 23)
│ │ ┌───────────── day of month (1 - 31)
│ │ │ ┌───────────── month (1 - 12)
│ │ │ │ ┌───────────── day of week (0 - 6) (Sunday=0)
│ │ │ │ │
* * * * * command
```

```bash
# Test the script manually:
sudo bash /usr/local/bin/monitoring.sh

# View cron jobs:
sudo crontab -l

# Temporarily disable without deleting:
sudo systemctl stop cron
```

---

## 🌟 Bonus Part

> 💡 The bonus sets up a **LEMP-like stack** (Lighttpd + MariaDB + PHP) hosting WordPress.

### 💡 WordPress Setup

Install dependencies first, then configure each service:

```bash
sudo apt install wget curl
```

### ⚡ Lighttpd

```bash
# Install
sudo apt install lighttpd

# Enable and start
sudo systemctl enable lighttpd
sudo systemctl start lighttpd

# Open port 80
sudo ufw allow 80

# Enable necessary modules
sudo lighttpd-enable-mod fastcgi
sudo lighttpd-enable-mod fastcgi-php

# Restart
sudo systemctl restart lighttpd
```

Configure document root:

```bash
sudo nano /etc/lighttpd/lighttpd.conf
```

Ensure:
```
server.document-root = "/var/www/html"
server.port = 80
```

---

### 🐬 MariaDB

```bash
# Install
sudo apt install mariadb-server

# Enable and start
sudo systemctl enable mariadb
sudo systemctl start mariadb

# Secure installation
sudo mysql_secure_installation
# Answer: n, Y, Y, Y, Y
```

#### Create WordPress Database

```bash
sudo mysql -u root -p
```

```sql
CREATE DATABASE wordpress;
CREATE USER 'wpuser'@'localhost' IDENTIFIED BY 'YourStrongPassword123!';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wpuser'@'localhost';
FLUSH PRIVILEGES;
EXIT;
```

---

### 🐘 PHP

```bash
# Install PHP and extensions
sudo apt install php-cgi php-common php-fpm php-mysql php-xml php-mbstring php-curl php-zip

# Verify
php -v
```

Configure Lighttpd for PHP:

```bash
sudo nano /etc/lighttpd/conf-available/15-fastcgi-php.conf
```

```
fastcgi.server += ( ".php" =>
    ((
        "socket" => "/var/run/php/php8.2-fpm.sock",
        "broken-scriptfilename" => "enable"
    ))
)
```

```bash
sudo lighty-enable-mod fastcgi fastcgi-php
sudo systemctl restart lighttpd php8.2-fpm
```

---

### 📦 Install WordPress

```bash
# Download WordPress
cd /tmp
wget https://wordpress.org/latest.tar.gz
tar -xzf latest.tar.gz

# Move to web root
sudo mv wordpress/* /var/www/html/
sudo chown -R www-data:www-data /var/www/html/
sudo chmod -R 755 /var/www/html/

# Configure WordPress
cd /var/www/html
sudo cp wp-config-sample.php wp-config.php
sudo nano wp-config.php
```

Edit these values:

```php
define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'wpuser' );
define( 'DB_PASSWORD', 'YourStrongPassword123!' );
define( 'DB_HOST', 'localhost' );
```

Visit `http://localhost` in your browser to finish WordPress setup!

---

### 🎁 Extra Service: Fail2ban

**Fail2ban** protects against brute-force attacks by banning IPs that fail authentication.

```bash
# Install
sudo apt install fail2ban

# Enable and start
sudo systemctl enable fail2ban
sudo systemctl start fail2ban

# Configure
sudo cp /etc/fail2ban/jail.conf /etc/fail2ban/jail.local
sudo nano /etc/fail2ban/jail.local
```

Configure SSH jail:

```ini
[sshd]
enabled  = true
port     = 4242
filter   = sshd
logpath  = /var/log/auth.log
maxretry = 3
bantime  = 600
findtime = 600
```

```bash
# Restart and verify
sudo systemctl restart fail2ban
sudo fail2ban-client status
sudo fail2ban-client status sshd
```

---

## ❓ Defense FAQ

These are the most common questions asked during the born2beroot defense:

<details>
<summary>💻 <strong>How does a virtual machine work?</strong></summary>

A VM is an emulation of a physical computer. The **hypervisor** (VirtualBox) acts as an abstraction layer, allocating CPU, RAM, and disk resources from the **host machine** to the **guest OS**. The guest OS is fully isolated and believes it's running on real hardware.

</details>

<details>
<summary>🐧 <strong>What is the difference between Debian and Rocky Linux?</strong></summary>

| Feature | Debian | Rocky Linux |
|---------|--------|-------------|
| Base | Community | RHEL-based |
| Package Manager | `apt` | `dnf` |
| Security Module | AppArmor | SELinux |
| Init System | systemd | systemd |
| Release Cycle | Stable/Testing/Unstable | Following RHEL |
| Default Shell | bash | bash |

</details>

<details>
<summary>🔑 <strong>What is the advantage of a strong password policy?</strong></summary>

A strong password policy:
- Prevents brute-force and dictionary attacks
- Reduces impact of credential stuffing
- Ensures password complexity limits guessability
- Regular expiry limits the window of exposure if a password is leaked

</details>

<details>
<summary>🛡️ <strong>What is sudo and why is it important?</strong></summary>

`sudo` (Super User DO) allows a permitted user to run commands as the superuser. It's important because:
- Logs all privileged commands (accountability)
- Limits root access to specific users
- Each command requires explicit invocation (no persistent root session)
- Can be restricted to specific commands per user

</details>

<details>
<summary>🔒 <strong>What is SSH and what does changing the port do?</strong></summary>

**SSH** (Secure Shell) is a cryptographic protocol for secure remote access. Changing the port from `22` to `4242`:
- Reduces automated bot scanning (most bots target port 22)
- Doesn't improve actual security, but reduces noise in logs
- Combined with `PermitRootLogin no`, significantly hardens access

</details>

<details>
<summary>🧱 <strong>What is UFW and how does it work?</strong></summary>

**UFW** (Uncomplicated Firewall) is a frontend for `iptables`. It manages **netfilter** kernel rules that filter network packets. 

```bash
sudo ufw status verbose     # See current rules
sudo ufw allow 4242         # Allow port 4242
sudo ufw deny 80            # Block port 80
```

It's "default deny" — everything is blocked unless explicitly allowed.

</details>

<details>
<summary>📊 <strong>How does your monitoring script work?</strong></summary>

The script collects system information using shell commands:
- `uname -a` → architecture
- `/proc/cpuinfo` → CPU info
- `free -m` → RAM usage
- `df -BG` → disk usage
- `top -bn1` → CPU load
- `who -b` → last boot
- `ss -tn` → TCP connections
- `journalctl` → sudo command count

It broadcasts the result using `wall`, which sends a message to all logged-in terminals. Cron runs it every 10 minutes.

</details>

<details>
<summary>🧱 <strong>What is LVM and why use it?</strong></summary>

LVM (Logical Volume Manager) provides a layer of abstraction between physical storage and filesystems:

```
Physical Disk → PV (Physical Volume) → VG (Volume Group) → LV (Logical Volume)
```

**Advantages over standard partitions:**
- Resize volumes without unmounting
- Easily span multiple disks
- Create snapshots for backups
- Flexible allocation of disk space

</details>

<details>
<summary>⚠️ <strong>What is AppArmor?</strong></summary>

**AppArmor** is a Linux Security Module that implements Mandatory Access Control via **profiles**. Each profile defines what files/network resources a program can access. 

- `enforce` mode: violations are blocked and logged
- `complain` mode: violations are logged but not blocked

```bash
sudo aa-status          # View loaded profiles
sudo aa-enforce <profile>  # Set to enforce mode
```

</details>

---

## 📚 Resources

### 📖 Official Documentation

| Resource | Link |
|----------|------|
| Debian Official Docs | [debian.org/doc](https://www.debian.org/doc/) |
| Debian Administrator's Handbook | [debian-handbook.info](https://www.debian-handbook.info/) |
| AppArmor Wiki | [wiki.ubuntu.com/AppArmor](https://wiki.ubuntu.com/AppArmor) |
| LVM Guide | [tldp.org/LVM-HOWTO](https://tldp.org/HOWTO/LVM-HOWTO/) |

### 🎓 Study Guides

| Resource | Link |
|----------|------|
| 42 Born2beRoot Guide by pasqualerossi | [GitHub](https://github.com/pasqualerossi/Born2BeRoot-Guide) |
| gemartin99's guide | [GitHub](https://github.com/gemartin99/Born2beroot-Tutorial) |
| LEMP Stack Guide | [DigitalOcean](https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mariadb-php-lemp-stack-on-debian-10) |

### 🛠️ Useful Commands Cheatsheet

```bash
# ── System Info ─────────────────────────────
uname -a                        # OS architecture info
hostname -I                     # IP address
cat /etc/os-release             # OS version

# ── Users & Groups ──────────────────────────
id <user>                       # User UID/GID/groups
getent passwd                   # All users
getent group                    # All groups
sudo chage -l <user>            # Password expiry info

# ── Services ────────────────────────────────
sudo systemctl status <service>
sudo systemctl enable <service>
sudo systemctl restart <service>

# ── Firewall ────────────────────────────────
sudo ufw status verbose
sudo ufw allow <port>

# ── Network ─────────────────────────────────
ss -tuln                        # Listening ports
ip a                            # Network interfaces

# ── Cron ────────────────────────────────────
sudo crontab -l                 # List cron jobs
sudo crontab -e                 # Edit cron jobs

# ── Disk ────────────────────────────────────
lsblk                           # Disk layout
df -h                           # Disk usage
free -h                         # RAM usage
```

---

## 🏆 Tips for a Perfect Defense

> Follow these and you'll ace it! 💪

- ✅ **Know your concepts** — AppArmor, LVM, sudo, UFW, SSH. Don't just configure them, *understand* them.
- ✅ **Practice your commands** — Be able to create users, change hostnames, add/remove firewall rules on the fly.
- ✅ **Take a snapshot** before your defense so you can revert if something goes wrong.
- ✅ **Double-check your hostname** — It must be `<your_login>42`.
- ✅ **Verify your groups** — Your user must be in `sudo` AND `user42`.
- ✅ **Test your monitoring script** — Run it manually and verify all values make sense.
- ✅ **Show the cron job** — `sudo crontab -l` should show the `*/10 * * * *` line.
- ✅ **Check password expiry** — `sudo chage -l <user>` for both your user and root.

---

<div align="center">

**Made with ❤️ by [Ayouub-aj](https://github.com/Ayouub-aj)**

*If this helped you, please ⭐ the repository!*

<img src="https://img.shields.io/github/stars/Ayouub-aj/born2beroot?style=social"/>

</div>
