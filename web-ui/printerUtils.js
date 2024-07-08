function extractInfo(data, prefix, padding) {
    const index = data.indexOf(prefix) + prefix.length;
    return data.substring(index, index + padding);
}

function processData(rawData, isReadingFiles) {
    const data = rawData.trim();

    if (data.includes('Begin file list')) {
        return {
            isReadingFiles: true,
        }
    }

    if (data.includes('End file list')) {
        return {
            isReadingFiles: false,
        }
    }

    if (isReadingFiles) {
        return {
            fileName: data,
        };
    }

    if (data.includes('T:')) {
        const nozzleTemp = extractInfo(data, 'T:', 6);
        $('#temperatureNozzle').html("Nozzle: " + nozzleTemp + " °C");
        const bedTemp = extractInfo(data, 'B:', 6);
        $('#temperatureBed').html("Bed: " + bedTemp + " °C");
        return {
            nozzleTemp: nozzleTemp,
        };
    }

    if (data.startsWith('X:')) {
        const x = extractInfo(data, 'X:', 6);
        $('#positionX').html("X: " + x + " mm");
        const y = extractInfo(data, 'Y:', 6);
        $('#positionY').html("Y: " + y + " mm");
        const z = extractInfo(data, 'Z:', 6);
        $('#positionZ').html("Z: " + z + " mm");
    }

    if (data.startsWith('echo:Print time:')) {
        const time = extractInfo(data, 'Print time:', 8);
        $('#elapsedTime').html(time);
        return {
            elapsedTime: time,
        }
    }
}
      // document.getElementById('progress-bar').style.width = data.progress + "%";
      // document.getElementById('progress-bar').innerText = data.progress + "%";
      // document.getElementById('position').innerText = data.position;
      // document.getElementById('status').innerText = data.status;