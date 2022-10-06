const form=document.querySelector("#searchForm")
const section=document.querySelector("section")
form.addEventListener("submit", async e=>{
e.preventDefault()
const SearchTerm= form.elements.query.value
const config={params:{ q:SearchTerm}}
const res=await axios.get(`https://api.tvmaze.com/search/shows`,config)
makeImages(res.data)
form.elements.query.value=""

})
const makeImages=(shows)=>{
    section.innerHTML=""
    for (let result of shows){
        if(result.show.image){
const img=document.createElement("img")
img.src=result.show.image.medium
section.append(img)
    }}
}