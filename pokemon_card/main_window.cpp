#include "main_window.h"

MainWindow::MainWindow()
{
	// Title
	setWindowTitle("Pokedex");

	pokemonNameDisplay = new QLabel();

	// Overall layout
	overallLayout = new QHBoxLayout();



	// // Selected pokemon display
	// Layout
	pokemonDisplayLayout = new QVBoxLayout();
	overallLayout->addLayout(pokemonDisplayLayout);


	// Pokemon image
	//TODO
	
	pokemonImageContainer = new QLabel();
	
	pokemonDisplayLayout->addWidget(pokemonImageContainer);

	// Pokemon name
	//TODO
	pokemonNameLabel = new QLabel("");
	pokemonDisplayLayout->addWidget(pokemonNameLabel);


	// Make it so image and name are at the top
	pokemonDisplayLayout->addStretch();




	// // List of all pokemon
	//TODO
	pokemonListWidget = new QListWidget();
	connect(pokemonListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(displayPokemon(int)));
	overallLayout->addWidget(pokemonListWidget);




	// // Form to add pokemon
	// Layout
	formLayout = new QVBoxLayout();
	overallLayout->addLayout(formLayout);


	// Pokemon name label
	pokemonNameLabel = new QLabel("Pokemon's Name:");
	formLayout->addWidget(pokemonNameLabel);

	// Pokemon name input
	//TODO
	pokemonNameInput = new QLineEdit();
	formLayout->addWidget(pokemonNameInput);
	

	// Image filename label
	imageFilenameLabel = new QLabel("Image Filename:");
	formLayout->addWidget(imageFilenameLabel);

	// Image filename input
	//TODO
	imageFilenameInput = new QLineEdit();
	formLayout->addWidget(imageFilenameInput);



	// Add button
	//TODO
	addButton = new QPushButton("Add Pokemon");
	connect(addButton, SIGNAL(clicked()), this, SLOT(addPokemon()));
	formLayout->addWidget(addButton);




	// Set overall layout
	setLayout(overallLayout);
}

MainWindow::~MainWindow()
{
	// Delete the images
	for(std::vector<QImage*>::iterator i = pokemonImages.begin();
		i != pokemonImages.end();
		++i)
	{
		delete *i;
	}

	//TODO the delete UI objects
	delete pokemonImageContainer;
	delete pokemonNameLabel;
	delete imageFilenameLabel;
	delete overallLayout;

}



void MainWindow::addPokemon()
{
	// Do nothing if user left at least one input blank
	//TODO
	if(pokemonNameInput->text().isEmpty() || imageFilenameInput->text().isEmpty())
	{
		return;
	}

	// // Get form values
	// Pokemon name
	//TODO
	pokemonNames.push_back(pokemonNameInput->text().toStdString());
	
	
	// Image
	


	QString filename = imageFilenameInput->text();
	QImage* newImage = new QImage();
	newImage->load(filename);
	//TODO what should go right here?
	pokemonImages.push_back(newImage);


	// Create a new list item with the pokemon's name
	//TODO
	pokemonListWidget->addItem(pokemonNameInput->text());


	// Clear the form inputs
	//TODO
	pokemonNameInput->setText("");
	imageFilenameInput->setText("");
}



void MainWindow::displayPokemon(int pokemonIndex)
{
	// Get the pokemon specified by the index,
	// which is passed into the function when
	// the user clicks on pokemonListWidget

	// Image
	QString pokemonText = QString::fromStdString(pokemonNames[pokemonIndex]);
	//pokemonText += "\"";
	pokemonNameDisplay->setText(pokemonText);

	// Pokemon name
	pokemonImageContainer->setPixmap(QPixmap::fromImage(*pokemonImages[pokemonIndex]));


}
