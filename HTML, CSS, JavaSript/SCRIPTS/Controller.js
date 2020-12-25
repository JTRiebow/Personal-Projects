function onPageLoad() {
    document.getElementById('createBtn').onclick = onCreateBtnClicked;
    document.getElementById('cancelBtn').onclick = onCancelBtnClicked;
    document.getElementById('newBtn').onclick = onNewBtnClicked;

    var items = modelGetAllFilms();
    for (var i = 0; i < items.length; i++)
        addTableItem(items[i]);

        clearInputForm();
}

/*************************************************************************/
function onCreateBtnClicked() {
    if (!validateControls())
        return;

    var form = document.forms["editForm"];
    var newFilm = modelCreateFilm(
        form.filmTitle.value,
        parseInt(form.filmCost.value),
        parseInt(form.filmProfit.value),
        form.filmDate.value,
        form.filmGenre.checked,
        form.filmAward.value);

        addTableItem(newFilm);

        clearInputForm();
}

/************************************************************************** */
function onNewBtnClicked() {
    document.getElementById('formTitle').innerHTML = "Create New Film";
    document.getElementById('filmEditArea').style.display='block';
    document.getElementById('filmListArea').style.display='none';
    document.getElementById("createBtn").style.display = "inline";
    document.getElementById("updateBtn").style.display = "none";
}
/************************************************************************** */
function onCancelBtnClicked() {
    clearInputForm();
}
/************************************************************************** */
function onEditBtnClicked(id) {
    var film = modelGetFilm(id);
    if (!film) {
        alert("Unable to find film with ID #" + id);
    }

    document.getElementById("formTitle").innerText = "Edit Film";
    var form = document.forms["editForm"];
    form.filmTitle.value = film.filmTitle;
    form.filmCost.value = film.filmCost;
    form.filmProfit.value = film.filmProfit;
    for (var date in form.filmDate.options) {
        var option = form.filmDate.options[date];
        if (option.value === film.filmDate) {
            option.selected = true;
        }
    }
    if (film.filmGenre === "action") {
        form.filmGenre[0].checked = true;
    }
    if (film.filmGenre === "sci-fi") {
        form.filmGenre[1].checked = true;
    }
    if (film.filmGenre === "horror") {
        form.filmGenre[2].checked = true;
    }
    if (film.filmGenre === "drama") {
        form.filmGenre[3].checked = true;
    }
    if (film.filmGenre === "doc") {
        form.filmGenre[4].checked = true;
    }
    if (film.filmGenre === "animated") {
        form.filmGenre[5].checked = true;
    }

    film.filmAward.checked = film.filmAward;

    document.getElementById("filmEditArea").style.display = "block";
    document.getElementById("filmListArea").style.display = "none";
    document.getElementById("createBtn").style.display = "none";

    var updateBtn = document.getElementById("updateBtn");
    updateBtn.style.display = "inline";
    updateBtn.onclick = function() {
        onUpdateBtnClicked(film.id);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
function validateControls() {
    var form = document.forms["editForm"];
    var validated = true;

    if (form.filmTitle.value === "") {
        document.getElementById("filmTitleError").innerHTML = "Film Title Not Given.";
        validated = false;
    }
    else {
        document.getElementById("filmTitleError").innerHTML = "";
    }
    
    if (form.filmCost.value === "") {
        document.getElementById("filmCostError").innerHTML = "Film Cost Not Given.";
        validated = false;
    }
    else if (isNaN(parseInt(form.filmCost.value))){
        document.getElementById("filmCostError").innerHTML = "Must Be A Number.";
        validated = false;
    }
    else if (parseInt(form.filmCost.value) < 0) {
        document.getElementById("filmCostError").innerHTML = "Must Be A Positive Number."
    }
    else {
        document.getElementById("filmCostError").innerHTML = "";
    }

    if (form.filmProfit.value === "") {
        document.getElementById("filmProfitError").innerHTML = "Film Profit Not Given";
        validated = false;
    }
    else if (isNaN(parseInt(form.filmProfit.value))){
        document.getElementById("filmProfitError").innerHTML = "Must Be A Number.";
        validated = false;
    }
    else if (parseInt(form.filmProfit.value) < 0) {
        document.getElementById("filmProfitError").innerHTML = "Must Be A Positive Number."
    }
    else {
        document.getElementById("filmProfitError").innerHTML = "";
    }

    if (form.filmDate.selectedIndex == -1) {
        document.getElementById("filmDateError").innerHTML = "Date Not Given.";
        validated = false;
    }
    else
        document.getElementById("filmDateError").innerHTML = "";

    if (form.actionRadio.checked == false && form.scifiRadio.checked == false && form.horrorRadio.checked == false && form.dramaRadio.checked == false && form.docRadio.checked == false && form.animatedRadio.checked == false) {
        document.getElementById("filmRadioError").innerHTML = "Genre Not Given.";
        validated = false;
    }
    else
        document.getElementById("filmRadioError").innerHTML = "";

    return validated;
}
/*******************************************************************************/
function addTableItem(film) {
    var table = document.getElementById("filmTable");
    var row = table.insertRow(table.rows.length);
    row.id = 'row' + film.id;

    var cell = row.insertCell(0);
    cell.innerHTML = film.filmTitle;

    cell = row.insertCell(1);
    cell.innerHTML = film.filmCost;

    cell = row.insertCell(2);
    cell.innerHTML = film.filmProfit;

    var editBtn = document.createElement("button");
    editBtn.type = "button";
    editBtn.innerText = "Edit";
    editBtn.onclick = function() {
        onEditBtnClicked(film.id);
    }

    cell = row.insertCell(3);
    cell.appendChild(editBtn);

    var deleteBtn = document.createElement("button");
    deleteBtn.type = "button";
    deleteBtn.innerText = "Delete";
    deleteBtn.onclick = function() {
        onDeleteBtnClicked(film.id);
    }

    cell = row.insertCell(4);
    cell.appendChild(deleteBtn);
}
/*********************************************************************************/
function clearInputForm() {
    document.getElementById('filmEditArea').style.display='none';
    document.getElementById('filmListArea').style.display='block';

    var form = document.forms["editForm"];

    form.filmTitle.value = "";
    document.getElementById("filmTitleError").innerHTML = "";

    form.filmCost.value = "";
    document.getElementById("filmCostError").innerHTML = "";

    form.filmProfit.value = "";
    document.getElementById("filmProfitError").innerHTML = "";

    form.filmDate.selectedIndex = -1;
    document.getElementById("filmDateError").innerHTML = "";

    form.actionRadio.checked = false;
    form.scifiRadio.checked = false;
    form.horrorRadio.checked = false;
    form.dramaRadio.checked = false;
    form.docRadio.checked = false;
    form.animatedRadio.checked = false;
    document.getElementById("filmRadioError").innerHTML = "";

    form.filmAward.checked = false;
    document.getElementById("filmAwardError").innerHTML = "";
}
/************************************************************************** */
function onUpdateBtnClicked(id) {
    if (!validateControls()) {
        return;
    }

    var form = document.forms["editForm"];
    var film = modelUpdateFilm(
        id,
        form.filmTitle.value,
        parseInt(form.filmCost.value),
        parseInt(form.filmProfit.value),
        form.filmDate.value,
        form.filmGenre.value,
        form.filmAward.checked);

        if (!film) {
            alert("Unable to update film id# =" + id);
            return;
        }

        var tr = document.getElementById("row" + id);
        tr.childNodes[0].innerText = film.filmTitle;
        tr.childNodes[1].innerText = film.filmCost;
        tr.childNodes[2].innerText = film.filmProfit;

        clearInputForm();
}

function onDeleteBtnClicked(id) {
    var film = modelGetFilm(id);
    if (!film) {
        alert("Unable to find film id# =" + id);
        return;
    }

    if (!confirm("Are you sure you want to delete " + film.filmTitle + "?")) {
        return;
    }

    modelDeleteFilm(id);

    var tr = document.getElementById("row" + id);
    tr.remove();

}