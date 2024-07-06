function processData(data) {
    const dataWithoutSpaces = data.trim();
    console.log('data without spaces', dataWithoutSpaces);
    if (dataWithoutSpaces.includes('T:')) {
        const index = dataWithoutSpaces.indexOf('T:') + 2;
        const temp = dataWithoutSpaces.substring(index, index + 6);
        console.log('temp', temp);
        document.getElementById('temperature').innerText = temp + " °C";
    }
}
      // document.getElementById('progress-bar').style.width = data.progress + "%";
      // document.getElementById('progress-bar').innerText = data.progress + "%";
      // document.getElementById('position').innerText = data.position;
      // document.getElementById('status').innerText = data.status;