function showNotification(message,header){
    $.toast({
        heading: header,
        text: message,
        position: 'top-right',
        loaderBg: '#fff',
        icon: 'warning',
        hideAfter: 3500,
        stack: 6
    })
}