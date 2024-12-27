
---

### **5. Projeyi Windows Ortamında Çalıştırma**

#### 5.1 **Linux Ortamı Sağlama**
Windows üzerinde Linux projesini çalıştırmak için şunları kullanabilirsiniz:
1. **WSL (Windows Subsystem for Linux)**:
   - Kurulum: [Microsoft WSL Kurulum Rehberi](https://learn.microsoft.com/en-us/windows/wsl/install)
   - Ubuntu gibi bir Linux dağıtımını yükledikten sonra terminalden devam edebilirsiniz.

2. **Sanal Makine (VM)**:
   - VirtualBox veya VMware kullanarak bir Linux VM oluşturabilirsiniz.

3. **Cygwin veya MinGW**:
   - Linux benzeri ortam sağlamak için bu araçları yükleyebilirsiniz.

#### 5.2 **Linux Üzerinde Projeyi Çalıştırma**
1. **Kodları Kopyalama**:
   - Proje dosyalarını Linux ortamına kopyalayın veya bir Git deposu üzerinden çekin:
     ```bash
     git clone <repository-url>
     cd myshell_project
     ```

2. **Projeyi Derleme**:
   ```bash
   make
