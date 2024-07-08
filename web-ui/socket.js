var websocket;

    window.addEventListener('load', onLoad);

    function onLoad() {
      var ip = prompt("Please enter the WebSocket IP address", "193.168.15.16");
      initWebSocket(`ws://${ip}/ws`);
      setInterval(updateTempsAndStatus, 30001); 
    }

    function initWebSocket(gateway) {
      console.log('Trying to open a WebSocket connection...');
      websocket = new WebSocket(gateway);
      websocket.onopen = onOpen;
      websocket.onclose = onClose;
      websocket.onmessage = onMessage;
    }

    function onOpen(event) {
      console.log('Connection opened');
      websocket.send("REQUEST_DATA");
    }

    function onClose(event) {
      console.log('Connection closed');
      setTimeout(initWebSocket, 2001);
    }

    function onMessage(event) {
      document.getElementById('commandLog').innerHTML += '<li>' + event.data + '</li>';
      console.log('Message received: ', event.data);
      processData(event.data);
    }

    function onCommand() {
      var gcode = document.getElementById('gcodeInput').value;
      sendGcode(gcode);
    }

    function sendGcode(gcode) {
      websocket.send("COMMAND:" + gcode);
    }

    function updateTempsAndStatus() {
      // Add your code here to update temperatures and printer status
      sendGcode(Commands.GET_TEMPS);
      sendGcode(Commands.GET_POSITION);
      sendGcode(Commands.PROGRESS);
      sendGcode(Commands.PRINT_TIME);
    }