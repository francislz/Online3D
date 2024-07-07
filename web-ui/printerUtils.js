function processData(data) {
    const dataWithoutSpaces = data.trim();
    console.log('data without spaces: ', dataWithoutSpaces);
    if (dataWithoutSpaces.includes('T:')) {
        const index = dataWithoutSpaces.indexOf('T:') + 2;
        const temp = dataWithoutSpaces.substring(index, index + 6);
        console.log('temp', temp);
        document.getElementById('temperatureNozzle').innerText = "Nozzle: " + temp + " °C";
    }

    if (dataWithoutSpaces.includes('B:')) {
        const index = dataWithoutSpaces.indexOf('B:') + 2;
        const temp = dataWithoutSpaces.substring(index, index + 6);
        console.log('temp', temp);
        document.getElementById('temperatureBed').innerText = "Bed: " + temp + " °C";
    }

    if (dataWithoutSpaces.startsWith('X:')) {
        const index = dataWithoutSpaces.indexOf('X:') + 2;
        const x = dataWithoutSpaces.substring(index, index + 6);
        console.log('x', x);
        document.getElementById('positionX').innerText = "X: " + x + " mm";
    }
}
      // document.getElementById('progress-bar').style.width = data.progress + "%";
      // document.getElementById('progress-bar').innerText = data.progress + "%";
      // document.getElementById('position').innerText = data.position;
      // document.getElementById('status').innerText = data.status;