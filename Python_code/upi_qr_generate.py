
import qrcode

upi_link = "upi://pay?pa=9911507140-3@ybl&pn=Anil+Kumar&am=500&cu=INR"
qr = qrcode.make(upi_link)
qr.save("upi_qr.png")

