# Basit Komut Satırı Yorumlayıcısı

## Proje Hakkında

Bu proje, İşletim Sistemleri dersi kapsamında basit bir komut satırı yorumlayıcısını (shell) simüle etmek amacıyla geliştirilmiştir. Kullanıcının girdiği komutları analiz eden, yönlendirme işlemlerini gerçekleştiren ve komutları çalıştıran bir sistem oluşturulmuştur.

## Özellikler

- **Komut Çalıştırma**: Kullanıcının girdiği komutları çalıştırır.
- **Arka Plan İşlemleri**: `&` sembolü ile arka planda işlem çalıştırma desteği.
- **Yönlendirme İşlemleri**:
  - Çıkış yönlendirme (`>` ve `>>`).
  - Giriş yönlendirme (`<`).

## Gereksinimler

Proje, aşağıdaki kütüphaneler ve POSIX sistem çağrılarını kullanır:

- `stdio.h`, `stdlib.h`, `string.h`
- `unistd.h`, `sys/types.h`, `sys/wait.h`

## Kullanım

### 1. Derleme
Shell yorumlayıcısını derlemek için aşağıdaki komut kullanılabilir:
```bash
gcc -o myshell myshell.c
```

### 2. Çalıştırma
Programı başlatmak için:
```bash
./myshell
```

### 3. Örnek Komutlar
Normal Komut: ls -l
Arka Plan İşlemi: sleep 10 &
Giriş Yönlendirme: cat < input.txt
Çıkış Yönlendirme: echo "Hello World" > output.txt


### Hazırlayanlar
#### Kadir Ataç (B221210020)
#### Ömer Asaf Balıkçı (B221210083)
#### Nihat Qadirli (B221210554)
#### Ahmet Safa Erginöz (B221210095)
#### Murat Yılmaz (B221210029)