#  Синхронизация нескольких потоков исполнения через потокобезопасную очередь сообщений на C++, с использованием паттерна "Мост"
### Приложение является трех поточным: один поток читает с устройства А, второй читает с устройства В, третий (основной поток приложения) разбирает и обрабатывает данные, прочитанные первыми двумя потоками. В качестве разделяемого буфера используется очередь сообщений. Очередь сообщений реализована как потокобезопасный класс EventQueue.
