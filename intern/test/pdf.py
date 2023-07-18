import PyPDF2
pdf_file = open('template.pdf', 'rb')
pdf_reader = PyPDF2.PdfFileReader(pdf_file)
num_pages = pdf_reader.numPages
for page_num in range(num_pages):
    page = pdf_reader.getPage(page_num)
    page_width = page.mediaBox.getWidth()
    page_height = page.mediaBox.getHeight()

    # Example: Retrieve the bottom left coordinates of the page
    x_bottom_left = 0  # X coordinate of the bottom left corner
    y_bottom_left = 0  # Y coordinate of the bottom left corner

    # Transform the coordinates to your desired system
    transformed_x = x_bottom_left
    transformed_y = page_height - y_bottom_left

    # Use the transformed coordinates as needed
    print(f"Page {page_num+1} - Transformed coordinates: ({transformed_x}, {transformed_y})")

