/*
 * Author: [Grup Üyeleri: Kadir Ataç, Murat Yılmaz, Ömer Asaf Balıkçı, Ahmet Safa Erginöz]
 * Proje İsmi: İşletim Sistemleri Ödevi - Basit Bir Komut Satırı Yorumlayıcısı
 * Açıklama: Bu proje, kullanıcının girdiği komutları analiz eden ve çalıştıran bir komut satırı yorumlayıcısını simüle eder.
 * Tarih: 24.12.2024
 */

#include <stdio.h>     // printf, perror, fflush için gerekli
#include <stdlib.h>    // exit için gerekli
#include <string.h>    // strlen ve strcpy gibi string işlemleri için gerekli
#include <unistd.h>    // fork, execvp, ve diğer POSIX işlemleri için gerekli
#include <sys/types.h> // pid_t için gerekli
#include <sys/wait.h>  // waitpid için gerekli

// Prompt görüntüleme
void print_prompt() {
    printf("> ");
    fflush(stdout);
}

// Komutları işleme
void execute_command(char *command) {
    int background = 0;

    // Arkaplan işlemleri kontrolü
    if (command[strlen(command) - 1] == '&') {
        background = 1;
        command[strlen(command) - 1] = '\0';
    }

    // Yeni süreç oluşturma
    pid_t pid = fork();
    if (pid == 0) {
        // handle_redirection fonksiyonu tanımlanmadığı için yorumlandı
        // handle_redirection(command); // Yönlendirme kontrolü
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execvp(args[0], args);
        perror("Komut çalıştırılamadı");
        exit(1);
    } else if (pid > 0) {
        if (!background) {
            waitpid(pid, NULL, 0); // Arkaplan değilse bekle
        } else {
            printf("[pid %d] arka planda çalışıyor\n", pid);
        }
    } else {
        perror("Fork başarısız");
    }
}

// Giriş ve çıkış yönlendirme işleme
void handle_redirection(char *command) {
    char *input_file = strstr(command, "<");
    char *output_file = strstr(command, ">");

    if (input_file) {
        *input_file = '\0'; // "<" kısmını kes
        input_file = strtok(input_file + 1, " \t\n");
        int fd_in = open(input_file, O_RDONLY);
        if (fd_in < 0) {
            perror("Giriş dosyası bulunamadı");
            exit(1);
        }
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }

    if (output_file) {
        *output_file = '\0'; // ">" kısmını kes
        output_file = strtok(output_file + 1, " \t\n");
        int fd_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd_out < 0) {
            perror("Çıkış dosyası açılamadı");
            exit(1);
        }
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);
    }
}