/*
 * Author: [Grup Üyeleri: Kadir Ataç, Murat Yılmaz, Ömer Asaf Balıkçı, Ahmet Safa Erginöz, NIHAD GADIRLI]
 * Proje İsmi: İşletim Sistemleri Ödevi - Basit Bir Komut Satırı Yorumlayıcısı
 * Açıklama: Bu proje, kullanıcının girdiği komutları analiz eden ve çalıştıran bir komut satırı yorumlayıcısını simüle eder.
 */

#ifndef MYSHELL_H
#define MYSHELL_H

// Komut satırı promptunu ekrana yazdırır
void print_prompt();

// Komuttaki yönlendirme işaretlerini (>, <, >>) işler
void handle_redirection(char *command);

// Verilen komutu çalıştırır
void execute_command(char *command);

#endif
