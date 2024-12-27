# Author: [Grup Üyeleri: Kadir Ataç, Murat Yılmaz, Ömer Asaf Balıkçı, Ahmet Safa Erginöz, NIHAD GADIRLI]
# Proje İsmi: İşletim Sistemleri Ödevi - Basit Bir Komut Satırı Yorumlayıcısı
# Açıklama: Bu proje, kullanıcının girdiği komutları analiz eden ve çalıştıran bir komut satırı yorumlayıcısını simüle eder.

# CC değişkeni, kullanılacak olan derleyiciyi tanımlar. Burada GNU C Compiler (gcc) kullanılıyor.
CC = gcc

# CFLAGS değişkeni, derleyiciye ek seçenekler sağlar. 
# -Wall: Tüm uyarı mesajlarını etkinleştirir.
# -g: Hata ayıklama bilgisi ekler.
CFLAGS = -Wall -g

# TARGET değişkeni, oluşturulacak çalıştırılabilir dosyanın adını tanımlar.
TARGET = myshell

# 'all' hedefi, make çalıştırıldığında çağrılır ve $(TARGET) dosyasını oluşturur.
all: $(TARGET)

# Bu kural, $(TARGET) dosyasını oluşturur.
# myshell.c dosyasını $(CC) derleyicisi ile $(CFLAGS) seçeneklerini kullanarak $(TARGET) adında çalıştırılabilir bir dosyaya dönüştürür.
$(TARGET): myshell.c
	$(CC) $(CFLAGS) -o $(TARGET) myshell.c

# 'clean' hedefi, derleme sırasında oluşturulan dosyaları temizler.
# Bu kural çağrıldığında, $(TARGET) dosyası silinir.
clean:
	rm -f $(TARGET)
