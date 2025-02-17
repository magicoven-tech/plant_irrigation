# Sistema de irrigação automática para plantas

![Badge Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)  
![Badge Plataforma](https://img.shields.io/badge/Plataforma-Arduino-blue)  
![Badge IoT](https://img.shields.io/badge/IoT-Opcional-green)

Este projeto visa criar um sistema de irrigação automático para plantas, capaz de monitorar a umidade do solo e ativar uma bomba de água quando necessário. O sistema é baseado em um microcontrolador e vai ser expandido para incluir funcionalidades como monitoramento remoto, coleta de dados e controle via aplicativo.

---

## Funcionalidades
- **Leitura da umidade do solo**: Utiliza um sensor de umidade para medir a quantidade de água no solo.
- **Irrigação automática**: Ativa uma bomba de água quando o solo está seco.

---

## Componentes necessários
- Microcontrolador (Arduino Nano)
- Sensor de umidade do solo (HW-390)
- Bomba de água
- Módulo relé (para controle da bomba)
- Fonte de energia (bateria 18650)
- Jumpers e protoboard (fase de prototipação)

---

## Como funciona
1. O sensor de umidade mede a quantidade de água no solo e envia os dados para o microcontrolador.
2. Se o solo estiver seco (valor acima do limite definido), o microcontrolador ativa a bomba de água por um período determinado.
3. O sistema exibe os dados de umidade no Serial Monitor, permitindo o acompanhamento em tempo real.

---

## Instalação e configuração
1. **Montagem do circuito**:
   - Conecte o sensor de umidade ao pino analógico do microcontrolador.
   - Conecte a bomba de água ao módulo relé e este ao microcontrolador.

2. **Upload do código**:
   - Conecte o microcontrolador ao computador.
   - Abra o código no Arduino IDE.
   - Defina o limite de umidade (`dryThreshold`) no código.
   - Faça o upload do código para o microcontrolador.

3. **Teste**:
   - Abra o Serial Monitor para ver os dados de umidade.
   - Verifique se a bomba é ativada quando o solo está seco.

---

## Expansões futuras
- Adicionar um módulo Wi-Fi (ESP32) para monitoramento remoto.
- Implementar um sistema de coleta de dados e análise histórica.
- Integrar sensores de temperatura e luminosidade para ajustar a irrigação conforme as condições ambientais.
- Desenvolver um aplicativo móvel para controle e notificações.

---

## Contribuição
Contribuições são bem-vindas! Se você quiser melhorar este projeto, siga os passos abaixo:
1. Faça um fork do repositório.
2. Crie uma branch para sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -m 'Adicionando nova feature'`).
4. Push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.

---

## Licença
Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT). Sinta-se à vontade para usar, modificar e distribuir o código.

---

## Contato
Se você tiver dúvidas ou sugestões, entre em contato:
- **Nome**: [Magic Oven](https://magicoven.tech)
- **E-mail**: [magicoven.tech@gmail.com](mailto:magicoven.tech@gmail.com?subject=Fala%20que%20eu%20te%20escuto&body=Olá%20no%20que%20posso%20ajudar?)
- **GitHub**: [magicoven.tech](https://github.com/magicoven-tech)
