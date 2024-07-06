function processData(data) {
    if (data.startsWith('T:')) {
        const index = data.indexOf('T:') + 2;
        const temp = data.substring(index);
        console.log('temp', temp);
        document.getElementById('temperature').innerText = temp + " °C";
    }
}
      // document.getElementById('progress-bar').style.width = data.progress + "%";
      // document.getElementById('progress-bar').innerText = data.progress + "%";
      // document.getElementById('position').innerText = data.position;
      // document.getElementById('status').innerText = data.status;